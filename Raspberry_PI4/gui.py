import sys
import os
import cv2
from PyQt5.QtWidgets import (
    QApplication, QMainWindow, QVBoxLayout, QLabel, QPushButton,
    QSlider, QFileDialog, QWidget, QHBoxLayout, QCheckBox, QStatusBar
)
from PyQt5.QtCore import Qt, QTimer
from PyQt5.QtGui import QImage, QPixmap, QFont
from ultralytics import YOLO

class YOLOv8GUI(QMainWindow):
    def __init__(self):
        super().__init__()
        self.setWindowTitle("Object Detection - YOLOv8")
        self.setGeometry(100, 100, 1200, 800)
        self.setStyleSheet("background-color: #F4F6F9;")  # Light, clean background color

        # Initialize YOLO model (default)
        self.model_path = 'yolov8n.pt'
        self.model = YOLO(self.model_path)

        # Layout and UI components
        self.central_widget = QWidget(self)
        self.setCentralWidget(self.central_widget)
        self.layout = QVBoxLayout(self.central_widget)

        # Header
        self.header_label = QLabel("Welding Defects Detection Interface", self)
        self.header_label.setFont(QFont("Arial", 24, QFont.Bold))
        self.header_label.setAlignment(Qt.AlignCenter)
        self.header_label.setStyleSheet("color: #4A90E2; padding: 20px;")
        self.layout.addWidget(self.header_label)

        self.sub_header_label = QLabel("Author: Lê Hải Anh", self)
        self.sub_header_label.setFont(QFont("Arial", 14))
        self.sub_header_label.setAlignment(Qt.AlignCenter)
        self.sub_header_label.setStyleSheet("color: #4A90E2; padding-bottom: 30px;")
        self.layout.addWidget(self.sub_header_label)

        # Display area
        self.video_label = QLabel(self)
        self.video_label.setFixedSize(1000, 550)
        self.video_label.setStyleSheet("background-color: #333333; border: 5px solid #4A90E2; border-radius: 10px;")
        self.video_label.setAlignment(Qt.AlignCenter)
        self.layout.addWidget(self.video_label)

        # Control buttons layout
        self.button_layout = QHBoxLayout()
        self.load_image_button = QPushButton("Load Image")
        self.load_image_button.setStyleSheet("background-color: #4A90E2; color: white; padding: 10px; border-radius: 5px;")
        self.load_image_button.clicked.connect(self.load_image)
        self.button_layout.addWidget(self.load_image_button)

        self.load_video_button = QPushButton("Load Video")
        self.load_video_button.setStyleSheet("background-color: #4A90E2; color: white; padding: 10px; border-radius: 5px;")
        self.load_video_button.clicked.connect(self.load_video)
        self.button_layout.addWidget(self.load_video_button)

        self.start_webcam_button = QPushButton("Start Webcam")
        self.start_webcam_button.setStyleSheet("background-color: #4A90E2; color: white; padding: 10px; border-radius: 5px;")
        self.start_webcam_button.clicked.connect(self.start_webcam)
        self.button_layout.addWidget(self.start_webcam_button)

        self.stop_button = QPushButton("Stop Detection")
        self.stop_button.setStyleSheet("background-color: #FF5722; color: white; padding: 10px; border-radius: 5px;")
        self.stop_button.clicked.connect(self.stop_detection)
        self.button_layout.addWidget(self.stop_button)

        self.load_model_button = QPushButton("Load Custom Model")
        self.load_model_button.setStyleSheet("background-color: #FF5722; color: white; padding: 10px; border-radius: 5px;")
        self.load_model_button.clicked.connect(self.load_model)
        self.button_layout.addWidget(self.load_model_button)

        self.layout.addLayout(self.button_layout)

        # Confidence threshold slider
        self.threshold_label = QLabel("Confidence Threshold: 0.25", self)
        self.threshold_label.setFont(QFont("Arial", 12))
        self.threshold_label.setStyleSheet("color: #4A90E2; padding-top: 30px;")
        self.layout.addWidget(self.threshold_label)

        self.threshold_slider = QSlider(Qt.Horizontal, self)
        self.threshold_slider.setMinimum(10)
        self.threshold_slider.setMaximum(100)
        self.threshold_slider.setValue(25)
        self.threshold_slider.setTickInterval(10)
        self.threshold_slider.setStyleSheet("QSlider::handle:horizontal {background-color: #4A90E2;}")
        self.threshold_slider.valueChanged.connect(self.update_threshold)
        self.layout.addWidget(self.threshold_slider)

        # Options
        self.options_layout = QHBoxLayout()

        self.dark_mode_checkbox = QCheckBox("Dark Mode")
        self.dark_mode_checkbox.setStyleSheet("color: #4A90E2;")
        self.dark_mode_checkbox.stateChanged.connect(self.toggle_dark_mode)
        self.options_layout.addWidget(self.dark_mode_checkbox)

        self.layout.addLayout(self.options_layout)

        # Status bar
        self.status_bar = QStatusBar()
        self.setStatusBar(self.status_bar)

        # Variables
        self.capture = None
        self.timer = QTimer(self)
        self.timer.timeout.connect(self.detect_objects)
        self.confidence_threshold = 0.25
        self.last_frame_time = 0

        # Set the timer interval to 200 ms for 5 FPS
        self.timer.setInterval(2000)  # 1000 ms / 5 FPS = 200 ms

    def update_threshold(self):
        self.confidence_threshold = self.threshold_slider.value() / 100
        self.threshold_label.setText(f"Confidence Threshold: {self.confidence_threshold:.2f}")

    def load_image(self):
        file_path, _ = QFileDialog.getOpenFileName(self, "Select Image", "", "Image Files (*.png *.jpg *.jpeg)")
        if file_path:
            frame = cv2.imread(file_path)
            self.process_frame(frame)

    def load_video(self):
        file_path, _ = QFileDialog.getOpenFileName(self, "Select Video", "", "Video Files (*.mp4 *.avi *.mov)")
        if file_path:
            self.capture = cv2.VideoCapture(file_path)
            self.start_detection()

    def start_webcam(self):
        self.capture = cv2.VideoCapture(0)
        self.start_detection()

    def start_detection(self):
        if self.capture is None or not self.capture.isOpened():
            self.status_bar.showMessage("Error: Unable to open video source.", 5000)
            return
        self.timer.start()

    def stop_detection(self):
        self.timer.stop()
        if self.capture is not None:
            self.capture.release()
        self.video_label.clear()

    def detect_objects(self):
        ret, frame = self.capture.read()
        if not ret:
            self.stop_detection()
            return

        # Process frame
        results = self.model(frame, conf=self.confidence_threshold)
        annotated_frame = results[0].plot()

        # Display processed frame
        self.display_frame(annotated_frame)

        # Update status bar
        object_count = len(results[0].boxes)
        self.status_bar.showMessage(f"Objects Detected: {object_count}")

    def process_frame(self, frame):
        results = self.model(frame, conf=self.confidence_threshold)
        annotated_frame = results[0].plot()
        self.display_frame(annotated_frame)

    def display_frame(self, frame):
        # Convert frame to QImage and display it
        height, width, channel = frame.shape
        bytes_per_line = 3 * width
        q_img = QImage(frame.data, width, height, bytes_per_line, QImage.Format_BGR888)
        pixmap = QPixmap.fromImage(q_img)
        self.video_label.setPixmap(pixmap)

    def load_model(self):
        file_path, _ = QFileDialog.getOpenFileName(self, "Select YOLO Model", "", "Model Files (*.pt)")
        if file_path:
            self.model_path = file_path
            self.model = YOLO(self.model_path)
            self.status_bar.showMessage(f"Model loaded: {self.model_path}", 5000)

    def toggle_dark_mode(self, state):
        if state == Qt.Checked:
            self.setStyleSheet("background-color: #2C2C2C;")
        else:
            self.setStyleSheet("background-color: #F4F6F9;")

if __name__ == "__main__":
    app = QApplication(sys.argv)
    window = YOLOv8GUI()
    window.show()
    sys.exit(app.exec())

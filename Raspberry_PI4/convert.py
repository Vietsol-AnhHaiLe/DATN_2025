import cv2
import os

def create_video_from_images(image_folder, output_video_path, fps=0.2):
    """
    Create a video from a sequence of images using OpenCV.

    :param image_folder: Path to the folder containing images.
    :param output_video_path: Path where the video will be saved.
    :param fps: Frames per second of the output video.
    """
    # Get list of image files in the folder
    images = [img for img in os.listdir(image_folder) if img.endswith(('.png', '.jpg', '.jpeg'))]
    images.sort()  # Sort to ensure the correct sequence

    # Read the first image to get frame size
    if not images:
        print("No images found in the specified folder.")
        return

    first_image_path = os.path.join(image_folder, images[0])
    frame = cv2.imread(first_image_path)
    height, width, layers = frame.shape
    size = (width, height)

    # Initialize video writer
    fourcc = cv2.VideoWriter_fourcc(*'mp4v')  # Use 'mp4v' for MP4 format
    video_writer = cv2.VideoWriter(output_video_path, fourcc, fps, size)

    # Write each image to the video
    for image in images:
        image_path = os.path.join(image_folder, image)
        frame = cv2.imread(image_path)
        if frame is None:
            print(f"Warning: Unable to read {image_path}. Skipping...")
            continue
        video_writer.write(frame)

    # Release the video writer
    video_writer.release()
    print(f"Video saved to {output_video_path}")

# Example usage
if __name__ == "__main__":
    image_folder = r"H:\Bosch\weld-dataset\kfold_high\fold0\train\images"  # Replace with your folder path
    output_video_path = "output_video.mp4"  # Replace with desired output path
    fps = 30  # Adjust the frames per second if needed

    create_video_from_images(image_folder, output_video_path, fps)

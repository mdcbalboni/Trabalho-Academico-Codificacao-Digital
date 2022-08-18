import os

# 1920x1080 -b:v 144k (0.8 * TBO 1080p)
os.system("ffmpeg -r 30 -i original-1080p.mp4 -s 1920x1080 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 9079k -minrate 9079k -maxrate 9079k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 1080p-80.mp4") 

# 1920x1080 -b:v 144k (0.6 * TBO 1080p)
os.system("ffmpeg -r 30 -i original-1080p.mp4 -s 1920x1080 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 6809k -minrate 6809k -maxrate 6809k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 1080p-60.mp4")

# 1920x1080 -b:v 108k (0.4 * TBO 1080p)
os.system("ffmpeg -r 30 -i original-1080p.mp4 -s 1920x1080 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 4539k -minrate 4539k -maxrate 4539k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 1080p-40.mp4")

# 1920x1080 -b:v 72k (0.2 * TBO 1080p)
os.system("ffmpeg -r 30 -i original-1080p.mp4 -s 1920x1080 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 2270k -minrate 2270k -maxrate 2270k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 1080p-20.mp4")



# 1280x720 -b:v 180k (TBO 720p)
os.system("ffmpeg -r 30 -i original-1080p.mp4 -s 1280x720 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 11349k -minrate 11349k -maxrate 11349k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 original-720p.mp4") 

# 1280x720 -b:v 144k (0.8 * TBO 720p)
os.system("ffmpeg -r 30 -i original-720p.mp4 -s 1280x720 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 9079k -minrate 9079k -maxrate 9079k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 720p-80.mp4")

# 1280x720 -b:v 108k (0.6 * TBO 720p)
os.system("ffmpeg -r 30 -i original-720p.mp4 -s 1280x720 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 6809k -minrate 6809k -maxrate 6809k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 720p-60.mp4")

# 1280x720 -b:v 72k (0.4 * TBO 720p)
os.system("ffmpeg -r 30 -i original-720p.mp4 -s 1280x720 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 4539k -minrate 4539k -maxrate 4539k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 720p-40.mp4")

# 1280x720 -b:v 36k (0.2 * TBO 720p)
os.system("ffmpeg -r 30 -i original-720p.mp4 -s 1280x720 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 2270k -minrate 2270k -maxrate 2270k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 720p-20.mp4")



# 1280x720 -b:v 180k (TBO 480p)
os.system("ffmpeg -r 30 -i original-1080p.mp4 -s 720x480 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 11349k -minrate 11349k -maxrate 11349k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 original-480p.mp4") 

# 1280x720 -b:v 144k (0.8 * TBO 480p)
os.system("ffmpeg -r 30 -i original-480p.mp4 -s 720x480 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 9079k -minrate 9079k -maxrate 9079k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 480p-80.mp4")

# 1280x720 -b:v 108k (0.6 * TBO 480p)
os.system("ffmpeg -r 30 -i original-480p.mp4 -s 720x480 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 6809k -minrate 6809k -maxrate 6809k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 480p-60.mp4")

# 1280x720 -b:v 72k (0.4 * TBO 480p)
os.system("ffmpeg -r 30 -i original-480p.mp4 -s 720x480 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 4539k -minrate 4539k -maxrate 4539k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 480p-40.mp4")

# 1280x720 -b:v 36k (0.2 * TBO 480p)
os.system("ffmpeg -r 30 -i original-480p.mp4 -s 720x480 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 2270k -minrate 2270k -maxrate 2270k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 480p-20.mp4")
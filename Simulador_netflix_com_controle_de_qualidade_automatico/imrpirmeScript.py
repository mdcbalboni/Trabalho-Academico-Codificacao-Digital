import os
#os.system("ffmpeg -r 30 -i original-1080p.mp4 -s 1280x720 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 11349k -minrate 11349k -maxrate 11349k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 original-720p.mp4") 
#os.system("ffmpeg -r 30 -i original-1080p.mp4 -s 720x480 -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v 11349k -minrate 11349k -maxrate 11349k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 original-480p.mp4") 
b=1080
d=1920
c=11349
for j in range(1,4):
	a=0.8
	for i in range(4):
		print 'os.system("ffmpeg -r 30 -i original-'+str(b)+'p.mp4 -s '+str(d)+"x"+str(b)+' -c:a aac -b:a 256k -strict -2 -c:v libx264 -b:v '+str(int(c*a))+'k -minrate '+str(int(c*a))+'k -maxrate '+str(int(c*a))+'k -bufsize 250k -x264opts keyint=120:min-keyint=120:scenecut=-1 '+str(b)+'p-'+str(int(a*100))+'.mp4)")'
		print " "
		a=a-0.2
	b=b-120*(4-j)
	d=d-80*(8-j+1)

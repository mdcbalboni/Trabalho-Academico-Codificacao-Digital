import os
lista = ("original-1080p.mp4","original-720p.mp4","original-480p.mp4")
aux=("1080p","720p","480p")
porcentagem = ("-80.mp4","-60.mp4","-40.mp4","-20.mp4")

for i in range(len(lista)):
	for j in range(len(porcentagem)):
		os.system("ffmpeg -i "+lista[i]+" -i "+aux[i]+porcentagem[j]+" -lavfi  'ssim;[0:v][1:v]psnr' -f null - &>> log.txt")

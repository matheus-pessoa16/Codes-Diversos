import cv2
import numpy as np

# DEFINICAO DAS FUNCOES

# conta os pixels nao brancos na imagem
def calculaArea(img):
    x = len(img)
    y = len(img[0])
    
    area = 0
    for i in range(0, x):
        for j in range(0, y):
            if img[i, j] != 255:
                area += 1

    return area   

def calculaAreaAproximada(img):
    x = len(img)
    y = len(img[0])
    
    area = 0
    for i in range(0, x):
        for j in range(0, y):
            if img[i, j] != 0:
                area += 1

    return area      


def segmentaMapa(img, areaColorida):
    x = len(img)
    y = len(img[0])
    
    shape = (x,y)

    norte = np.zeros(shape)
    nordeste = np.zeros(shape)
    sul = np.zeros(shape)
    sudeste = np.zeros(shape)
    centro = np.zeros(shape)

    for i in range(0, x):
        for j in range(0, y):
            if img[i, j] != 255:                
                if img[i ,j] == 226:
                    norte[i,j] = img[i,j]
    
    for i in range(0, x):
        for j in range(0, y):
            if img[i, j] != 255:                
                if img[i ,j] > 77 and img[i, j] <= 82:
                    nordeste[i,j] = img[i,j]

    for i in range(0, x):
        for j in range(0, y):
            if img[i, j] != 255:                
                if img[i ,j] == 76:
                    centro[i,j] = img[i,j]

    for i in range(0, x):
        for j in range(0, y):
            if img[i, j] != 255:                
                if img[i ,j] >= 87 and img[i, j] <= 90:
                    sudeste[i,j] = img[i,j]

    for i in range(0, x):
        for j in range(0, y):
            if img[i, j] != 255:                
                if img[i ,j] >= 175 and img[i, j] <= 179:
                    sul[i,j] = img[i,j]

    kernel = np.ones((3,3),np.uint8)
    kernelErosion = np.ones((2,2),np.uint8)
    
    # areaTotal = calculaArea(img)

    closeNorte = cv2.morphologyEx(norte, cv2.MORPH_CLOSE, kernel, iterations = 2)
    # erosionNorte = cv2.erode(closeNorte,kernelErosion,iterations = 1)
    cv2.imshow('Norte', closeNorte)
    areaNorte = calculaAreaAproximada(closeNorte)
    print('Área do Norte %s' % areaNorte)
    areaPercentNorte = (areaNorte/areaColorida) * 100
    print('Área percentual ocupada pelo Norte : %s ' % areaPercentNorte )

    closeNordeste = cv2.morphologyEx(nordeste, cv2.MORPH_CLOSE, kernel, iterations = 1)
    erosionNordeste = cv2.erode(closeNordeste,kernelErosion,iterations = 1)
    cv2.imshow('Nordeste', erosionNordeste)
    areaNordeste = calculaAreaAproximada(erosionNordeste)
    print('Área do Nordeste %s' % areaNordeste)
    areaPercentNordeste = (areaNordeste/areaColorida) * 100
    print('Área percentual ocupada pelo Nordeste : %s ' % areaPercentNordeste )

    closeCentro = cv2.morphologyEx(centro, cv2.MORPH_CLOSE, kernel, iterations = 2)
    erosionCentro = cv2.erode(closeCentro,kernelErosion,iterations = 1)    
    cv2.imshow('Centro', erosionCentro)
    areaCentro = calculaAreaAproximada(erosionCentro)
    print('Área do Centro %s' % areaCentro)
    areaPercentCentro = (areaCentro/areaColorida) * 100
    print('Área percentual ocupada pelo Centro : %s ' % areaPercentCentro )

    closeSudeste = cv2.morphologyEx(sudeste, cv2.MORPH_CLOSE, kernel)
    #erosionSudeste = cv2.erode(closeSudeste ,kernelErosion,iterations = 1)
    cv2.imshow('Sudeste', closeSudeste)
    areaSudeste = calculaAreaAproximada(closeSudeste)
    print('Área do Sudeste %s' % areaSudeste)
    areaPercentSudeste = (areaSudeste/areaColorida) * 100
    print('Área percentual ocupada pelo Sudeste : %s ' % areaPercentSudeste )

    closeSul = cv2.morphologyEx(sul, cv2.MORPH_CLOSE, kernel, iterations = 1)
    #erosionSul = cv2.erode(closeSul,kernelErosion,iterations = 1)
    cv2.imshow('Sul',closeSul)
    areaSul = calculaAreaAproximada(closeSul)
    print('Área do Sul %s' % areaSul)
    areaPercentSul = (areaSul/areaColorida) * 100
    print('Área percentual ocupada pelo Sul : %s ' % areaPercentSul )
    
    areaTotal = (areaCentro+areaNordeste+areaNorte+areaSudeste+areaSul) * 100
    areaTotal = areaTotal / areaColorida
    print('Áreas somadas: %s' % areaTotal)


# FIM DO BLOCO DE FUNÇÕES

# abrindo a imagem em tons de cinza
img = cv2.imread('mapa.jpg', 0)

# binarizando a imagem
ret,thresh1 = cv2.threshold(img,230,255,cv2.THRESH_BINARY)

# cálculo da área
areaColorida = calculaArea(thresh1)
print(areaColorida)
segmentaMapa(img, areaColorida)
cv2.imshow('mapa', img)
cv2.waitKey(0)

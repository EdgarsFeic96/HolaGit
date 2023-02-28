import matplotlib.pyplot as plt
import random
from time import time

def intercambia(B,i):
    tmp=B[i]
    B[i]=B[i+1]
    B[i+1]=tmp

def bubbleSortM(A):
    n=len(A)
    b=1
    p=0
    while p<n-1 and b==1:
        b=0
        for j in range(n-p-1):
            if A[j]>A[j+1]:
                b=1
                intercambia(A,j)
        p+=1

def MergeSort(A,p,r):
    if p<r:
        q=int((p+r)/2)        
        MergeSort(A,p,q)
        MergeSort(A,q+1,r)
        Merge(A,p,q,r)

def Merge(A,p,q,r):
    izq=A[p:q+1]
    der=A[q+1:r+1]
    i=0
    j=0
    for k in range(p,r+1):
        if (j>=len(der)) or (i<len(izq) and izq[i]<der[j]):
            A[k]=izq[i]
            i+=1
        else:
            A[k]=der[j]
            j+=1

def graficas():
    n=[k*100 for k in range(1,31)]
    print(n)
    TM=[]
    TB=[]
    for k in n:
        datosOM=random.sample(range(1,100000000,k)
        datosOB=datosOM[:]  ##copia los datos en vez de apuntar
        tini=time()
        MergeSort(datosOM,0,len(datosOM)-1)
        tfin=time()
        TM.append(round(tfin-tini,6))
        tini=time()
        buubleSortM(datosOB)
        tfin=time()
        TB.append(round(tfin-tini,6))  
    
    fig,ax=plt.subplots()
    ax.plot(n,TM,label="MS",marker="*",color="r")
    ax.plot(n,TB,label="Bs",marker="*",color="b")                        
    ax.set_xlabel("tamaño secuencia")
    ax.set_ylabel("T(n)")
    ax.grid(True)
    plt.title("M vs B")
    plt.show()                                  
graficas()
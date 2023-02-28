import matplotlib.pyplot as plt
import random
from time import time

def change(B,i):
    temp=B[i]
    B[i]=B[i+1]
    B[i+1]= temp
def bubbleSortS (A):
    n = len(A)
    for i in range(n-1):
        for j in range (n-1):
            if A[j]>A[j+1]:
                change(A,j)
def bubbleSortM(A):
    n= len(A)
    flag = 1
    step = 0
    while step < n-1 and flag == 1:
        flag = 0
        for j in range(n-step-1):
            if A[j]>A[j+1]:
                flag=1
                change(A,j)
        step+=1

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
    for k in range (p,r+1):
        if (j>=len(der)) or (i<len(izq)) and izq[i]<der[j]:
            A[k]= izq[i]
            i+=1
        else:
            A[k]=der[j]
            j+=1
def intercambiar(A,i,mini):
    temp=A[i]
    A[i]=A[mini]
    A[mini]=temp
def OrdenSelec(A):
    n=len(A)
    for i in range(0,n):
        mini=i;
        for j in range(i+1,n):
            if A[j]<A[mini]:
                
                mini=j      
        intercambiar(A,i,mini)

def InsertionSort(A,n):
    for j in range(n):
        llave=A[j]
        i=(j-1)
        while i>=0 and A[i]>llave:
            A[i+1] = A[i]
            i=i-1
        A[i+1] = llave

def graficas():
    n=[k*100 for k in range(1,31)]
    TM=[]
    TB=[]
    SS=[]
    IS=[]
    for k in n:
        datosOM = random.sample(range(1,100000),k)
        datosOB=datosOM[:]
        datosSS=datosOM[:]
        datosIS=datosOM[:]
        tini=time()
        MergeSort(datosOM,0,len(datosOM)-1)
        tfin=time()
        TM.append(round(tfin-tini,6))
        
        tini=time()
        OrdenSelec(datosSS)
        tfin=time()
        TM.append(round(tfin-tini,6))

        tini=time()
        InsertionSort(datosIS,len(datosIS)-1)
        tfin=time()
        TM.append(round(tfin-tini,6))
        
        tini=time()
        bubbleSortM(datosOB)
        tfin=time()
        TB.append(round(tfin-tini,6))
    fig,ax= plt.subplots()
    ax.plot(n,TM,label="MS",marker="",color="r")
    ax.plot(n,TB,label="BS",marker="*",color="b")
    ax.plot(n,IS,label="IS",marker="",color="y")
    ax.plot(n,SS,label="SS",marker="*",color="g")
    ax.set_xlabel("Tamaño secuencia")
    ax.set_ylabel("Tiempo")
    ax.grid(True)
    plt.title("Merge vs Bubble vs Insertion  vs Selection")
    plt.show()

def main():
    #L=[1,5,3,8,2,7,4]
    #print(L)
    #bubbleSortS(L)
    #bubbleSortM(L)
    #MergeSort(L,0,len(L)-1)
    #print(L)
    graficas()


void BubbleSort(int a[],n)

{

int i,j,temp;

for(i=1;i<n;i++)

{ bool flag = false for(j=0;j<n-i;j++) { if(a[j]>a[j+1]) { flag = true temp=a[j]; a[j]=a[j+1]; a[j+1]=temp;

}

}

if(!flag) break;

}

}
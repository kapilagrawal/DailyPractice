#include <stdio.h>

int main() {

	int i=0, t=0;
	scanf("%d", &t);
	
	while(t!=0){
	    int sz=0;
	    scanf("%d", &sz);
	    
	    int arr[sz];
	    for(i=0;i<sz;i++){
	        scanf("%d ", &arr[i]);
	    }
	    
	    for(i=0;i<=(sz-1)/2;i++){
	        int temp=0;
	        temp = arr[i];
	        arr[i] = arr[sz-1-i];
	        arr[sz-1-i] = temp;
	    }
	    for(i=0;i<sz;i++){
	        printf("%d ", arr[i]);
	    }
	    printf("\n");
	    t--;
	}
	return 0;
}

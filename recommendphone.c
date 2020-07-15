#include<stdio.h>
#include<math.h>

//Scan the information in the "price.txt" file, which contains mobile phone brand, 
//model and price information, and write the program that has the price closest to the average (may be equal) to the "recommend.txt" file in accordance with the sample file below. 
//Describe the structure called struct cellphone whose members are brand (string), 
//model (string) and price (double). Transfer the records in the “price.txt” file into an array of up to 100 elements of the struct cellphone type

struct cellphone{
	
	char brand[100];
	char model[100];
	double price;
	
};

int main(){
	
	struct cellphone c[100];
	
	FILE *f=fopen("price.txt","w+");
	
	int n,i;
	
	printf("How many telephone objects will you enter?:");
	scanf("%d",&n);
	
	
	for(i=0;i<n;i++){
		printf("%d.th Phone informations (brand, model, price):",i+1);
		scanf("%s%s%lf",&c[i].brand,&c[i].model,&c[i].price);
	}
	for(i=0;i<n;i++){
		fprintf(f,"%s %s %.1f\n",c[i].brand,c[i].model,c[i].price);
	}

    f=fopen("price.txt","r");

	for(i=0;i<n;i++){
		fscanf(f,"%s%s%lf\n",&c[i].brand,&c[i].model,&c[i].price);
	}
	for(i=0;i<n;i++){
		printf("%s %s %.1f\n",c[i].brand,c[i].model,c[i].price);
	}
	
	double sum=0.0;
	
	for(i=0;i<n;i++){
		sum+=c[i].price;
	}
	
	double avrg=sum/n*1.0;
	
    int k,a=0;
    double min=abs(avrg-c[0].price);
    
    for(k=1;k<n;k++){
    	if(abs(avrg-c[k].price)<=min){
    		min=c[k].price;
    		a=k;
		}
	}

	FILE *ff=fopen("recommend.txt","w");

	fprintf(ff,"\nAvegare:%.1f",avrg*1.0);
	fprintf(ff,"\nThe mobile phone we recommend:%s %s %.1f",c[a].brand,c[a].model,min);
	
	fclose(f);
	fclose(ff);
	
	
	return 0;
}

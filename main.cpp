#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data, data_oncelik;
	struct node *next;
}*oncelikli_kuyruk;

void push(int, int);
void pop();			
void del();
void elemanlariGoster();

int main()
{
	int secim, eleman, oncelik_durumu, dongu=1;
	printf("\n 1 - Eleman Ekleme islemi");
    	printf("\n 2 - Eleman Cikarma islemi");
    	printf("\n 3 - Eleman Sergileme islemi");
    	printf("\n 4 - Cikis");
    
while(dongu==1)
{
	printf("\n Seciminizi Giriniz : ");
    scanf("%d", &secim);
	switch(secim)
	{
		case 1:
			printf("\n Eklemek istediginiz elemani ve oncelik durumunu giriniz. ");
			printf("\n Ornegin: 666 33 // yani eklenen elemanman 666 oncelik durumu 33\n");
			scanf("%d%d",&eleman,&oncelik_durumu);
			push(eleman,oncelik_durumu);
			break;
		case 2:
			del();
			break;
		case 3:
			elemanlariGoster();
			break;
		case 4:
			dongu=0; //Stops the loop
			break;
		default:
			printf("Yanlis secim yaptiniz. Lutfen seciminizi 1-4 araliginda yapiniz");
	printf("\n Devam etmek icin 0 yada 1'e basiniz'");
	scanf("%d",&dongu);
	}
}
return 0;
}
/************************** Kuyruk Eleman Sergileme Kismi ***************************///buketecrinozturk

void elemanlariGoster()
{
	struct node *gecici_list;
	gecici_list = oncelikli_kuyruk;
	printf("\Oncelikli Kuyruk: ");
	while(gecici_list!=NULL)
	{
		printf("%d,%d ",gecici_list->data, gecici_list->data_oncelik);
		gecici_list=gecici_list->next;
	}

printf("\n");
}

/************************** Kuyruk Eleman Ekleme Kismi ***************************///buketecrinozturk

void push(int eleman,int oncelik)
{
	struct node *gecici_list, *o_k;
	gecici_list = (struct node *)malloc(sizeof(struct node));
	gecici_list->data=eleman;
	gecici_list->data_oncelik=oncelik;
	gecici_list->next=NULL;
	
	if(oncelikli_kuyruk==NULL)
		oncelikli_kuyruk = gecici_list;
	else if(oncelikli_kuyruk->data_oncelik>oncelik)
	{
		gecici_list->next=oncelikli_kuyruk;
		oncelikli_kuyruk=gecici_list;
	}
	else
	{
	o_k=oncelikli_kuyruk;
		while(o_k->next!=NULL && (o_k->next)->data_oncelik<=oncelik )
			o_k=o_k->next;
			gecici_list->next=o_k->next;
			o_k->next=gecici_list;
	}
elemanlariGoster();
}

/************************** Kuyruk Eleman Silme Kismi ***************************///buketecrinozturk

void del()
{
	if(oncelikli_kuyruk!=NULL)
	{
	printf("\n\Cikarilan eleman: %d",oncelikli_kuyruk->data);
	oncelikli_kuyruk = oncelikli_kuyruk->next;
	elemanlariGoster();
	}
	else
	printf("\n Liste Bos!!!");
}




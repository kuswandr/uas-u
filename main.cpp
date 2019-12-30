#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;


struct struct_data {
	int id_item;
	char item_desc[20];
	float price;
};
struct_data data_item[] = {
	{0,"Nasi Cadong",5000},
	{1,"Tongseng", 10000},
	{2,"Marimas Boba", 3000},
	{3,"Es Teh", 2000}
};

struct summary {
	int id_item;
	int amount;
};

summary summary_sale[] = {
	{0,0},
	{1,0},
	{2,0},
	{3,0}
};

struct item{
	int id_item;
	char item_desc[20];
	float price_item;
	int amount;
	float price_amount;
};
	
struct order{
	int id_table;
	int status;
	int order_amount;
	float total_price_table;
	item order_item[10];
};
order tables[4];
int index();
int menu_1();
int menu_2();
int menu_3();
int header();
int set_free(int ts);
int show_daftar_menu(int nm);
int show_detail_order(int nm);
int update_order_table(int nm);
float calculate_price(int id, int amount);
int add_summary(int id);

main() {
	system("cls");
	int index_pilih;
	index();
	scanf("%i", &index_pilih);
	switch (index_pilih) {
		case 1: 
			menu_1();
			break;
		case 2:
			menu_2();
			break;
		case 3:
			menu_3();
			break;
		case 0:
			exit(0);
			break;
	}
	getch();
}

header() {
	printf("====================================================\n");
	printf("\t\t    Cafe Gas! \n");
	printf("\tJl. Godean Km 18 No. 69 , Sleman YK \n");
	printf("====================================================\n");
}

index() {
	header();
	printf("\t\tWelcome bro bro bro! \n\n");
	printf("\tMenu : \n");
	printf("\t\t1. New Order\n");
	printf("\t\t2. List Table\n");
	printf("\t\t3. Summary Order\n");
	printf("\t\t0. Exit\n\n");
	printf("====================================================\n");
	printf(" Choose menu :");
	return 0;
}

menu_1(){
	system("cls");
	int no_table;
	int index_table;
	int index_item = 0;
	float total_price_table;
	header();
	printf("\t\tCreate New Order: \n\n");
	
	printf("Masukkan Nomor Meja (1-4): ");
	scanf("%i", &no_table);
	if(no_table == 0){
		index_table = no_table;
	}else{
		index_table = no_table - 1;
	}
	tables[index_table].id_table = no_table;
	tables[index_table].status = 1;
	
	show_add_item:
		char add_again = 'y';
		system("cls");
		header();
		printf("\t\tCreate New Order: \n\n");
		show_daftar_menu(tables[index_table].id_table);
		printf("\nMasukan No Item = ");
		scanf("%i", &tables[index_table].order_item[index_item].id_item);
		printf("Masukan Jumlah item = ");
		scanf("%i", &tables[index_table].order_item[index_item].amount);	
		tables[index_table].order_item[index_item].price_item = data_item[tables[index_table].order_item[index_item].id_item].price;
		strcpy(tables[index_table].order_item[index_item].item_desc, data_item[tables[index_table].order_item[index_item].id_item].item_desc);
		tables[index_table].order_item[index_item].price_amount = tables[index_table].order_item[index_item].price_item * tables[index_table].order_item[index_item].amount;
		printf("Id Item  |Item \t\t |Jumlah    |Harga     | Harga jumlah");
		printf("\n|%8i|%15s|%10i|%10.2f|%10.2f\n\n", 
			tables[index_table].order_item[index_item].id_item,
			tables[index_table].order_item[index_item].item_desc,
			tables[index_table].order_item[index_item].amount,
			tables[index_table].order_item[index_item].price_item,
			tables[index_table].order_item[index_item].price_amount
		);
		total_price_table += tables[index_table].order_item[index_item].price_amount;
		summary_sale[tables[index_table].order_item[index_item].id_item].amount += tables[index_table].order_item[index_item].amount;
	printf("Tambah item?[y/n] ");
	scanf("%s", &add_again);
	if(add_again == 'y'){
		index_item += 1;
		goto show_add_item;
	}else{
		system("cls");
		header();
		printf("\t\tNew Order Created! \n\n");
		printf("Nomor Meja : %i \n", tables[index_table].id_table);
		printf("Id Item  |Item \t\t |Jumlah    |Harga     | Harga jumlah");
		for(int i = 0; i <= index_item; i++){
			printf("\n|%8i|%15s|%10i|%10.2f|%10.2f", 
				tables[index_table].order_item[i].id_item,
				tables[index_table].order_item[i].item_desc,
				tables[index_table].order_item[i].amount,
				tables[index_table].order_item[i].price_item,
				tables[index_table].order_item[i].price_amount
			);	
		}
		printf("\n-------------------------------------Total Harga : %.2f \n", total_price_table);
		printf("Press any key to go back to main menu");
		tables[index_table].order_amount = index_item+1;
		tables[index_table].total_price_table = total_price_table;
		getch();
		main();
	}
	
}

menu_2(){
	system("cls");
	int menu_pilih;
	int table_selected;
	header();
	printf("\t\tList Table Order: \n\n");
	for (int i = 0; i < 4; i++){
		printf("\t\t(%i) Table %i \n", i+1, i+1);
		if(tables[i].status == 1){
			printf("\t\t Status : (Isi) \n");
		}else{
			printf("\t\t Status : (Kosong) \n\n");
		}
	}
	
	printf(" \t 1. Detail Order \n");
	printf(" \t 2. Set Free \n");
	printf(" \t 0. Back\n");
	printf(" Choose menu :"); 
	scanf("%i", &menu_pilih);
	switch (menu_pilih){
		case 1:
			printf(" Masukkan nomor meja = ");
			scanf("%i", &table_selected);
			show_detail_order(table_selected);
			break;
		case 2:
			printf(" Masukkan nomor meja = ");
			scanf("%i", &table_selected);
			set_free(table_selected);
			break;
		case 0:
			main();
			break;
	}
}

set_free(int ts){
	int index_table = ts-1;
	tables[index_table].id_table = 0;
	tables[index_table].status = 0;
	tables[index_table].total_price_table = 0;
	tables[index_table].order_amount = 0;
	menu_2();
}

float calculate_summary(int am, float pr){
	float result;
	
	result = am * pr;
	return result;
}

menu_3(){
	system("cls");
	header();
	int i, menu_pilih;
	float total_all;
	printf(" No.| Description \t   | Amount | Price\n");
	while (i < 4){
		printf("%3i.| %20s |  %5i | %.2f \n", 
			i,
			data_item[i].item_desc,
			summary_sale[i].amount,
			calculate_summary(summary_sale[i].amount, data_item[i].price)
		);
		total_all += calculate_summary(summary_sale[i].amount, data_item[i].price);
		i++;
	}
	printf("----------------------Total Summary : %.2f \n\n", total_all);
	printf(" 0. Back\n");
	printf(" Choose menu :");
	scanf("%i", &menu_pilih);
	switch(menu_pilih){
		case 0 :
			main();
			break;
		default :
			main();
			break;
	}
}



show_detail_order(int nm){
	system("cls");
	header();
	int menu_pilih;
	int index_table = nm - 1;
	printf("Nomor Meja : %i \n", tables[index_table].id_table);
	printf("Id Item  |Item \t\t |Jumlah    |Harga     | Harga jumlah");
	for(int i = 0; i < tables[index_table].order_amount; i++){
		printf("\n|%8i|%15s|%10i|%10.2f|%10.2f", 
			tables[index_table].order_item[i].id_item,
			tables[index_table].order_item[i].item_desc,
			tables[index_table].order_item[i].amount,
			tables[index_table].order_item[i].price_item,
			tables[index_table].order_item[i].price_amount
		);	
	}
	printf("\n-------------------------------------Total Harga : %.2f \n", tables[index_table].total_price_table);
	printf("\n\n 1. Add Item");
	printf("\n 0. back\n");
	printf(" Choose menu :");
	scanf("%i", &menu_pilih);
	switch(menu_pilih){
		case 1 :
			update_order_table(index_table);
			break;
		case 0 :
			menu_2();
			break;
		default :
			menu_2();
			break;
	}
}

update_order_table(int index_table){
	int index_item = tables[index_table].order_amount;
	float total_price_table = tables[index_table].total_price_table;
	show_add_item:
		char add_again = 'y';
		system("cls");
		header();
		printf("\t\tUpdate Order: \n\n");
		show_daftar_menu(tables[index_table].id_table);
		printf("\nMasukan No Item = ");
		scanf("%i", &tables[index_table].order_item[index_item].id_item);
		printf("Masukan Jumlah item = ");
		scanf("%i", &tables[index_table].order_item[index_item].amount);	
		tables[index_table].order_item[index_item].price_item = data_item[tables[index_table].order_item[index_item].id_item].price;
		strcpy(tables[index_table].order_item[index_item].item_desc, data_item[tables[index_table].order_item[index_item].id_item].item_desc);
		tables[index_table].order_item[index_item].price_amount = tables[index_table].order_item[index_item].price_item * tables[index_table].order_item[index_item].amount;
		printf("Id Item  |Item \t\t |Jumlah    |Harga     | Harga jumlah");
		printf("\n|%8i|%15s|%10i|%10.2f|%10.2f\n\n", 
			tables[index_table].order_item[index_item].id_item,
			tables[index_table].order_item[index_item].item_desc,
			tables[index_table].order_item[index_item].amount,
			tables[index_table].order_item[index_item].price_item,
			tables[index_table].order_item[index_item].price_amount
		);
		total_price_table += tables[index_table].order_item[index_item].price_amount;
		summary_sale[tables[index_table].order_item[index_item].id_item].amount += tables[index_table].order_item[index_item].amount;
	printf("Tambah item?[y/n] ");
	scanf("%s", &add_again);
	if(add_again == 'y'){
		index_item += 1;
		goto show_add_item;
	}else{
		tables[index_table].order_amount = index_item+1;
		tables[index_table].total_price_table = total_price_table;
		show_detail_order(tables[index_table].id_table);
	}
}


show_daftar_menu(int nm){
	printf("Nomor Meja : %i \n", nm);
	printf("-----------------------Food :-----------------------\n");
	printf("No Item | Name \t\t| Price \n");
	printf("  0\t| Nasi Cadong\t| 5000\n");
	printf("  1\t| Tongseng\t| 10000\n");
	
	printf("---------------------Beverage :---------------------\n");
	printf("No Item | Name \t\t| Price \n");
	printf("  2\t| Marimas Boba\t| 3000\n");
	printf("  3\t| Es Teh\t| 2000\n");
}



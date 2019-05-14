/*
Nama	: Bandana Irmal Abdillah
NPM		: 140810180025
Tanggal	: 14 Mei 2019
Deskripsi: exercise-02 strukdat-10
*/

#include <iostream>
using namespace std;

struct ElementQueue{
	char info ;
	ElementQueue* next;
};

typedef ElementQueue* pointer;
typedef pointer list;

struct queue{
	list head;
	list tail;
};

queue  q;

void createElmt(pointer& pBaru){
	pBaru= new ElementQueue;;
	cout<<"Masukan Antrian : "; cin >> pBaru->info;
	pBaru->next = 0;
}

void enqueue(queue& q, pointer pBaru){
	if(q.head == 0 & q.tail == 0){
		q.head = pBaru;
		q.tail = pBaru;
	}
	else{
		q.tail->next = pBaru;
		q.tail = q.tail->next;
	}
}

void deleteQueue(queue& q,pointer& pHapus){
	if(q.head == 0 && q.tail == 0){
    	pHapus = 0;
    	cout<<"Kosong";
  	}
  	else if(q.head->next == 0){
    	pHapus = q.head;
    	q.head = 0;
    	q.tail = 0;
  	}
  	else{
    	pHapus = q.head;
    	q.head = q.head->next;
    	pHapus->next = 0;
  	}
}

void traversal(queue q)
{
	pointer pBantu;
	pBantu = q.head;
	while(pBantu != 0){
    	cout << pBantu->info<<" ";
    	pBantu = pBantu->next;
  	}
}

main()
{
  	pointer pb,ph;
  	int n;
  	cout <<"Masukan Banyak Antrian	: "; cin >> n;
	for(int i=0;i<n;i++){
    	createElmt(pb);
    	enqueue(q, pb);
	}
	cout << "List antrian : ";
    traversal(q);
    cout << endl << endl <<"Delete Queue : ";
    deleteQueue(q, ph);
    traversal(q);
    
}

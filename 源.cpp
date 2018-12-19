#include"链表.h"
#include"顺序表.h"
#include"栈.h"
#include"队列.h"
int main()
{
	//    cout<<"Input the number of elements you want to push in:\n";
 //   int num=0;
 //   cin>>num;

 //   Linelist<int> Linelist_test(num);

 //   cout<<"Input the elements with blank space to separate:\n";

 //   for(int i=1; i<=5; i++)
 //   {
 //       int item=0;
 //       cin>>item;
 //       Linelist_test.Insert(i,item);
 //   }

 //   cout<<"The current Linelist:  ";
 //   Linelist_test.Show_list(Show_item);

 //   //插入操作
 //   {
 //       int pos=0;
 //       int item=0;
 //       cout<<"Input the position you want to insert :\n";
 //       cin>>pos;
 //       cout<<"Input the element you want to insert:  ";
 //       cin>>item;
 //       Linelist_test.Insert(pos,item);
 //       cout<<"The current Linelist:  ";
 //       Linelist_test.Show_list(Show_item);
 //   }
	////删除操作
	//{
	//	int pos=0;
 //       int item=0;
 //       cout<<"Input the position you want to delete :\n";
 //       cin>>pos;
 //        Linelist_test.Delete_poi(pos,item);
 //       cout<<"The element you want to delete is :  "<<item<<endl;
 //       cout<<"The current Linelist:  ";
 //       Linelist_test.Show_list(Show_item);
	//}
//
	//cout << "Input the number of elements you want to push in:\n";
	//int num = 0;
	//cin >> num;
	//Linklist<int> Linklist_test(num);
	//cout << "Input the elements with blank space to separate:\n";
	//for (int i = 0; i < num; i++)
	//{
	//	int item = 0;
	//	cin >> item;
	//	Linklist_test.Insert(item);
	//}
	//cout << "The current Linklist is : \n";
	//Linklist_test.ShowList();
	////插入操作
	//{
	//	int pos = 0;
	//	int item = 0;
	//	cout << "Input the position you want to insert :\n";
	//	cin >> pos;
	//	cout << "Input the element you want to insert:  ";
	//	cin >> item;
	//	cin.get();
	//	// cout<<endl<<pos<<"  "<<item<<endl;
	//	Linklist_test.Insert(pos, item);
	//	cout << "The current Linelist:  ";
	//	Linklist_test.ShowList();
	//}
	////删除操作
	//{
	//	int pos = 0;
	//	int item = 0;
	//	cout << "Input the position you want to delete :\n";
	//	cin >> pos;
	//	Linklist_test.Delete(pos, item);
	//	cin.get();
	//	//cout<<endl<<pos<<"  "<<item<<endl;
	//	cout << "The element you want to delete is :  " << item << endl;
	//	cout << "The current Linelist:  ";
	//	Linklist_test.ShowList();
	//}
	////输出表长
	//{
	//	cout << "\nThe current Linklist's length is:  " << Linklist_test.Length() << endl;
	//}

	//***********栈测试程序*************
	//Stack<int> test_stack(100);
	//for (int i = 0; i < 50; i++)
	//	test_stack.push(i);

	//int length = test_stack.Length();
	//cout << "The length of the stack:" << ' ' << length << endl;
	//int topitem = 0;
	//test_stack.Gettop(topitem);
	//cout << "The top item of the stack:  " << topitem << endl;


	//test_stack.Showstack();
	//
	//cout << "After Reverse: \n";
	//test_stack.Reverse(1,10);
	//test_stack.Showstack();

	//cout << "After Clear:\n";
	//test_stack.Clear(1, 10, 20);
	//test_stack.Showstack();

	//cout << "After copy:\n";
	//Stack<int> test1 = test_stack;
	//test1.Showstack();


	Queue<int> test_queue(20);
	for (int i = 0; i < 20; i++)
		test_queue.Enqueue(i);



	cout << "The queue shows below:\n";
	cout << test_queue;

	cout << "After copy:\n";
	Queue<int> test1(10);
	test1 = test_queue;
	//test1.Showqueue();
	cout << test1;

//	cout << "The first and last one of the queue:  " << test_queue.Locate(1) << "  " << test_queue.Locate(length) << endl;

	int length = test1.Length();
	cout << "THe length of the queue:  " << length << endl;

	cout << "After Insert:\n";
	int item = 20;
	test1.Insert_queue(item, 19);
	cout << test1;
	return 0;
}
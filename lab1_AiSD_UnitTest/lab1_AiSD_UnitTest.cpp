#include "pch.h"
#include "CppUnitTest.h"
#include "../lab1_AiSD/lab1_AiSD_MapRBTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab1AiSDUnitTest
{
	TEST_CLASS(lab1AiSDUnitTest)
	{
	public:
		TEST_METHOD(ConsrtructorStackTest)
		{
			stack<int> MyStack;
			Assert::IsTrue(MyStack.size() == 0);
		}
		TEST_METHOD(DesrtructorStackTest)
		{
			stack<int> MyStack;
			MyStack.push(3);
			Assert::IsTrue(MyStack.size() == 1);
			MyStack.~stack();
			Assert::IsTrue(MyStack.size() == 0);
		}
		TEST_METHOD(PushStackTest)
		{
			stack<int> MyStack;
			MyStack.push(3);
			Assert::IsTrue(MyStack.top() == 3);
			MyStack.push(7);
			Assert::IsTrue(MyStack.top() == 7);
		}
		TEST_METHOD(PopStackTest)
		{
			stack<int> MyStack;
			MyStack.push(3);
			Assert::IsTrue(MyStack.size() == 1);
			MyStack.push(7);
			Assert::IsTrue(MyStack.size() == 2);
			MyStack.pop();
			Assert::IsTrue(MyStack.size() == 1);
		}
		TEST_METHOD(TopStackTest)
		{
			stack<int> MyStack;
			MyStack.push(3);
			Assert::IsTrue(MyStack.top() == 3);

			MyStack.push(7);
			Assert::IsTrue(MyStack.top() == 7);
			MyStack.pop();
			Assert::IsTrue(MyStack.top() == 3);
		}
		TEST_METHOD(SizeStackTest)
		{
			stack<int> MyStack;
			Assert::IsTrue(MyStack.size() == 0);
			MyStack.push(3);
			Assert::IsTrue(MyStack.size() == 1);
			MyStack.push(7);
			Assert::IsTrue(MyStack.size() == 2);
			MyStack.pop();
			Assert::IsTrue(MyStack.size() == 1);
		}
		TEST_METHOD(EmptyStackTest) 
		{
			stack<int> MyStack;
			Assert::IsTrue(MyStack.empty() == 1);
			MyStack.push(3);
			Assert::IsTrue(MyStack.empty() == 0);
			MyStack.push(7);
			Assert::IsTrue(MyStack.empty() == 0);
			MyStack.pop();
			Assert::IsTrue(MyStack.empty() == 0);
		}
		TEST_METHOD(ConsrtructorLinkedListTest)
		{
			Linked_list<int> MyLinked_list;
			Assert::IsTrue(MyLinked_list.size() == 0);
		}
		TEST_METHOD(DesrtructorLinkedListTest)
		{
			Linked_list<int> MyLinked_list;
			Assert::IsTrue(MyLinked_list.size() == 0);
			MyLinked_list.insert_node(17);
			Assert::IsTrue(MyLinked_list.size() == 1);
			MyLinked_list.~MyLinked_list();
			Assert::IsTrue(MyLinked_list.size() == 0);

		}
		TEST_METHOD(InsertNodeLinkedListTest)
		{
			Linked_list<int> MyLinked_list;
			MyLinked_list.insert_node(17);
			Assert::IsTrue(MyLinked_list.get_head() == 17);
			MyLinked_list.insert_node(7);
			MyLinked_list.set_next();
			Assert::IsTrue(MyLinked_list.get_head() == 7);
		}
		TEST_METHOD(GetHeadLinkedListTest)
		{
			Linked_list<int> MyLinked_list;
			try {
				MyLinked_list.get_head();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("List is empty", error.what());
			}
				MyLinked_list.insert_node(17);
				Assert::IsTrue(MyLinked_list.get_head() == 17);
				MyLinked_list.insert_node(7);
				MyLinked_list.set_next();
				Assert::IsTrue(MyLinked_list.get_head() == 7);
		}
		TEST_METHOD(SetNextLinkedListTest)
		{
			Linked_list<int> MyLinked_list;
			MyLinked_list.insert_node(17);
			Assert::IsTrue(MyLinked_list.get_head() == 17);
			try {
				MyLinked_list.set_next();
			}
			catch (const out_of_range error) {
				Assert::AreEqual("There is not next element", error.what());
			}
		}
		TEST_METHOD(SizeLinkedListTest)
		{
			Linked_list<int> MyLinked_list;
			Assert::IsTrue(MyLinked_list.size() == 0);
			MyLinked_list.insert_node(17);
			Assert::IsTrue(MyLinked_list.size() == 1);
			MyLinked_list.insert_node(7);
			Assert::IsTrue(MyLinked_list.size() == 2);
		}
		TEST_METHOD(DeleteNodeLinkedListTest) {
			Linked_list<int> MyLinked_list;
			Assert::IsTrue(MyLinked_list.size() == 0);
			MyLinked_list.insert_node(17);
			Assert::IsTrue(MyLinked_list.size() == 1);
			MyLinked_list.~Linked_list();
			Assert::IsTrue(MyLinked_list.size() == 0);
		}
		TEST_METHOD(ConsrtructorCustomMapTest)
		{
			CustomMap<char, int> MyCustomMap;
			MyCustomMap.insert('a', 1);
			Assert::IsTrue(MyCustomMap.find('a')->value == 1);
			try {
				MyCustomMap.find('b');
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
		}
		TEST_METHOD(DesrtructorCustomMapTest)
		{
			CustomMap<char, int> MyCustomMap;
			MyCustomMap.insert('a', 1);
			Assert::IsTrue(MyCustomMap.find('a')->value == 1);
			try {
				MyCustomMap.find('b');
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
			MyCustomMap.insert('b', 2);
			Assert::IsTrue(MyCustomMap.find('b')->value == 2);
			MyCustomMap.~CustomMap();
			try {
				MyCustomMap.find('a');
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
			try {
				MyCustomMap.find('b');
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
		}
		TEST_METHOD(InsertCustomMapTest) {
			CustomMap<int, int> MyCustomMap;
			MyCustomMap.insert(1, 1);
			Assert::IsTrue(MyCustomMap.find(1)->color == 0);
			MyCustomMap.insert(3, 3);
			Assert::IsTrue(MyCustomMap.find(1)->color == 0);
			Assert::IsTrue(MyCustomMap.find(3)->color == 1);
			MyCustomMap.insert(5, 5);
			Assert::IsTrue(MyCustomMap.find(3)->color == 0);
			Assert::IsTrue(MyCustomMap.find(1)->color == 1);
			Assert::IsTrue(MyCustomMap.find(5)->color == 1);
			MyCustomMap.insert(7, 7);
			Assert::IsTrue(MyCustomMap.find(3)->color == 0);
			Assert::IsTrue(MyCustomMap.find(1)->color == 0);
			Assert::IsTrue(MyCustomMap.find(5)->color == 0);
			Assert::IsTrue(MyCustomMap.find(7)->color == 1);
		}
		TEST_METHOD(RemoveCustomMapTest) {
			CustomMap<int, int> MyCustomMap;
			MyCustomMap.insert(1, 1);
			Assert::IsTrue(MyCustomMap.find(1)->color == 0);
			MyCustomMap.insert(3, 3);
			Assert::IsTrue(MyCustomMap.find(1)->color == 0);
			Assert::IsTrue(MyCustomMap.find(3)->color == 1);
			MyCustomMap.insert(5, 5);
			Assert::IsTrue(MyCustomMap.find(3)->color == 0);
			Assert::IsTrue(MyCustomMap.find(1)->color == 1);
			Assert::IsTrue(MyCustomMap.find(5)->color == 1);
			MyCustomMap.insert(7, 7);
			Assert::IsTrue(MyCustomMap.find(3)->color == 0);
			Assert::IsTrue(MyCustomMap.find(1)->color == 0);
			Assert::IsTrue(MyCustomMap.find(5)->color == 0);
			Assert::IsTrue(MyCustomMap.find(7)->color == 1);
			MyCustomMap.remove(5);
			Assert::IsTrue(MyCustomMap.find(3)->color == 0);
			Assert::IsTrue(MyCustomMap.find(1)->color == 0);
			try {
				MyCustomMap.find(5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
			Assert::IsTrue(MyCustomMap.find(7)->color == 0);
		}
		TEST_METHOD(FindCustomMapTest) {
			CustomMap<int, char> MyCustomMap;
			MyCustomMap.insert(1, 'a');
			Assert::IsTrue(MyCustomMap.find(1)->value == 'a');
			MyCustomMap.insert(3, 'b');
			Assert::IsTrue(MyCustomMap.find(1)->value == 'a');
			Assert::IsTrue(MyCustomMap.find(3)->value == 'b');
			MyCustomMap.insert(5, 'c');
			Assert::IsTrue(MyCustomMap.find(3)->value == 'b');
			Assert::IsTrue(MyCustomMap.find(1)->value == 'a');
			Assert::IsTrue(MyCustomMap.find(5)->value == 'c');
			MyCustomMap.insert(7, 'd');
			Assert::IsTrue(MyCustomMap.find(3)->value == 'b');
			Assert::IsTrue(MyCustomMap.find(1)->value == 'a');
			Assert::IsTrue(MyCustomMap.find(5)->value == 'c');
			Assert::IsTrue(MyCustomMap.find(7)->value == 'd');
			MyCustomMap.remove(5);
			Assert::IsTrue(MyCustomMap.find(3)->value == 'b');
			Assert::IsTrue(MyCustomMap.find(1)->value == 'a');
			try {
				MyCustomMap.find(5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
			Assert::IsTrue(MyCustomMap.find(7)->value == 'd');
		}
		TEST_METHOD(ClearCustomMapTest) {
			CustomMap<int, char> MyCustomMap;
			MyCustomMap.insert(1, 'a');
			MyCustomMap.insert(3, 'b');
			MyCustomMap.insert(5, 'c');
			MyCustomMap.insert(7, 'd');
			MyCustomMap.clear();
			try {
				MyCustomMap.find(1);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
			try {
				MyCustomMap.find(3);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
			try {
				MyCustomMap.find(5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
			try {
				MyCustomMap.find(7);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
		}
		TEST_METHOD(GetKeysCustomMapTest) {
			CustomMap<int, int> MyCustomMap;
			MyCustomMap.insert(13, 31);
			MyCustomMap.insert(8, 18);
			MyCustomMap.insert(17, 71);
			Linked_list<int> hello = MyCustomMap.get_keys();
			Assert::IsTrue(hello.get_head() == 13);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 8);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 17);
		}
		TEST_METHOD(GetValuesCustomMapTest) {
			CustomMap<int, int> MyCustomMap;
			MyCustomMap.insert(13, 31);
			MyCustomMap.insert(8, 18);
			MyCustomMap.insert(17, 71);
			Linked_list<int> hello = MyCustomMap.get_values();
			Assert::IsTrue(hello.get_head() == 31);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 18);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 71);
		}
		TEST_METHOD(MovingCustomMapTest) {
			CustomMap<int, int> MyCustomMap;
			MyCustomMap.insert(90, 1);
			MyCustomMap.insert(101, 2);
			MyCustomMap.insert(15, 3);
			Assert::IsTrue(MyCustomMap.find(90)->left->key == 15);
			Assert::IsTrue(MyCustomMap.find(15)->right->key < 0);
			MyCustomMap.remove(15);
			Assert::IsTrue(MyCustomMap.find(90)->left->key < 0 );
		}
		TEST_METHOD(LeftRotateCustomMapTest) {
			CustomMap<int, int> MyCustomMap;
			MyCustomMap.insert(93, 1);
			MyCustomMap.insert(100, 2);
			MyCustomMap.insert(15, 3);
			MyCustomMap.insert(17, 4);
			MyCustomMap.insert(30, 5);
			Assert::IsTrue(MyCustomMap.find(17)->color == 0);
			Assert::IsTrue(MyCustomMap.find(30)->color == 1);
			MyCustomMap.insert(42, 6);
			Assert::IsTrue(MyCustomMap.find(17)->color == 1);
			Assert::IsTrue(MyCustomMap.find(30)->color == 0);
			Assert::IsTrue(MyCustomMap.find(42)->color == 1);
		}
		TEST_METHOD(RightRotateCustomMapTest) {
			CustomMap<int, int> MyCustomMap;
			MyCustomMap.insert(93, 1);
			MyCustomMap.insert(100, 2);
			MyCustomMap.insert(15, 3);
			MyCustomMap.insert(17, 4);
			MyCustomMap.insert(30, 5);
			MyCustomMap.insert(42, 6);
			Assert::IsTrue(MyCustomMap.find(17)->color == 1);
			Assert::IsTrue(MyCustomMap.find(30)->color == 0);
			Assert::IsTrue(MyCustomMap.find(30)->right->key == 42);
			Assert::IsTrue(MyCustomMap.find(42)->color == 1);
			MyCustomMap.insert(40, 7);
			Assert::IsTrue(MyCustomMap.find(30)->color == 1);
			Assert::IsTrue(MyCustomMap.find(30)->right->key < 0);
			Assert::IsTrue(MyCustomMap.find(40)->right->key == 42);
		}
		TEST_METHOD(FixAfterInsertCustomMapTest) {
			CustomMap<int, int> MyCustomMap;
			MyCustomMap.insert(93, 1);
			MyCustomMap.insert(100, 2);
			MyCustomMap.insert(15, 3);
			Assert::IsTrue(MyCustomMap.find(100)->color == 1);
			Assert::IsTrue(MyCustomMap.find(15)->color == 1);
			MyCustomMap.insert(17, 4);
			Assert::IsTrue(MyCustomMap.find(100)->color == 0);
			Assert::IsTrue(MyCustomMap.find(15)->color == 0);
			Assert::IsTrue(MyCustomMap.find(17)->color == 1);
		}
		TEST_METHOD(FixAfterRemoveCustomMapTest) {
			CustomMap<int, int> MyCustomMap;
			MyCustomMap.insert(93, 1);
			MyCustomMap.insert(100, 2);
			MyCustomMap.insert(15, 3);
			MyCustomMap.insert(17, 4);
			Assert::IsTrue(MyCustomMap.find(100)->color == 0);
			Assert::IsTrue(MyCustomMap.find(15)->color == 0);
			Assert::IsTrue(MyCustomMap.find(17)->color == 1);
			MyCustomMap.remove(100);
			Assert::IsTrue(MyCustomMap.find(17)->color == 0);
			Assert::IsTrue(MyCustomMap.find(15)->color == 0);
			Assert::IsTrue(MyCustomMap.find(93)->color == 0);
		}
		TEST_METHOD(FindAlgorithmCustomMapTest) {
			CustomMap<int, char> MyCustomMap;
			MyCustomMap.insert(1, 'a');
			Assert::IsTrue(MyCustomMap.find(1)->value == 'a');
			MyCustomMap.insert(3, 'b');
			Assert::IsTrue(MyCustomMap.find(1)->value == 'a');
			Assert::IsTrue(MyCustomMap.find(3)->value == 'b');
			MyCustomMap.insert(5, 'c');
			Assert::IsTrue(MyCustomMap.find(3)->value == 'b');
			Assert::IsTrue(MyCustomMap.find(1)->value == 'a');
			Assert::IsTrue(MyCustomMap.find(5)->value == 'c');
			MyCustomMap.insert(7, 'd');
			Assert::IsTrue(MyCustomMap.find(3)->value == 'b');
			Assert::IsTrue(MyCustomMap.find(1)->value == 'a');
			Assert::IsTrue(MyCustomMap.find(5)->value == 'c');
			Assert::IsTrue(MyCustomMap.find(7)->value == 'd');
			MyCustomMap.remove(5);
			Assert::IsTrue(MyCustomMap.find(3)->value == 'b');
			Assert::IsTrue(MyCustomMap.find(1)->value == 'a');
			try {
				MyCustomMap.find(5);
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
			Assert::IsTrue(MyCustomMap.find(7)->value == 'd');
		}
		TEST_METHOD(RBTreeToStackCustomMapTest) {
			CustomMap<char, int> MyCustomMap;
			MyCustomMap.insert('a', 1);
			MyCustomMap.insert('b', 2);
			MyCustomMap.insert('c', 3);
			Assert::IsTrue(MyCustomMap.find('a')->value == 1);
			Assert::IsTrue(MyCustomMap.find('b')->value == 2);
			Assert::IsTrue(MyCustomMap.find('c')->value == 3);
			MyCustomMap.~CustomMap();
			try {
				MyCustomMap.find('a');
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
			try {
				MyCustomMap.find('b');
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
			try {
				MyCustomMap.find('a');
			}
			catch (const out_of_range error) {
				Assert::AreEqual("Couldn't find key in the RBTree", error.what());
			}
		}
		TEST_METHOD(GetKeysAlgorithmCustomMapTest) {
			CustomMap<int, int> MyCustomMap;
			MyCustomMap.insert(13, 31);
			MyCustomMap.insert(8, 18);
			MyCustomMap.insert(17, 71);
			Linked_list<int> hello = MyCustomMap.get_keys();
			Assert::IsTrue(hello.get_head() == 13);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 8);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 17);
		}
		TEST_METHOD(GetValuesAlgorithmCustomMapTest) {
			CustomMap<int, int> MyCustomMap;
			MyCustomMap.insert(13, 31);
			MyCustomMap.insert(8, 18);
			MyCustomMap.insert(17, 71);
			Linked_list<int> hello = MyCustomMap.get_values();
			Assert::IsTrue(hello.get_head() == 31);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 18);
			hello.set_next();
			Assert::IsTrue(hello.get_head() == 71);
		}
	};
}

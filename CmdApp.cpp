#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include<iostream>
#include<numeric>
#include<queue>
#include <unordered_map>
//#include "LinkedList.h"
#include "BSTCpp14.h"
#include "Graph.h"
#include "Recurssion.h"
#include "Unique_Ptr.h"
#include "MoveSemantics.cpp"
#include "SharedPtr.h"
#include "HeapProblems.h"
#include "StackProblems.h"
#include "BinSearch.h"
#include "SlidingWindow.h"
//void list_client(void)
//{
//    list_t* p_list = NULL;
//    data_t data;
//    status_t status;
//
//    p_list = create_list();
//
//    status = get_start(p_list, &data);
//    assert(status == LIST_EMPTY);
//    status = get_end(p_list, &data);
//    assert(status == LIST_EMPTY);
//
//    status = pop_start(p_list, &data);
//    assert(status == LIST_EMPTY);
//    status = pop_end(p_list, &data);
//    assert(status == LIST_EMPTY);
//
//    status = remove_start(p_list);
//    assert(status == LIST_EMPTY);
//    status = remove_end(p_list);
//    assert(status == LIST_EMPTY);
//
//    if (is_list_empty(p_list) == TRUE)
//        puts("List is initially empty");
//
//    for (data = 0; data < 5; ++data)
//    {
//        status = insert_start(p_list, data);
//        assert(status == SUCCESS);
//    }
//
//    show_list(p_list);
//
//    for (data = 5; data < 10; ++data)
//    {
//        status = insert_end(p_list, data);
//        assert(status == SUCCESS);
//    }
//
//    show_list(p_list);
//
//    status = insert_after(p_list, -10, 100);
//    assert(status == LIST_DATA_NOT_FOUND);
//
//    status = insert_before(p_list, -10, 100);
//    assert(status == LIST_DATA_NOT_FOUND);
//
//    status = insert_after(p_list, 0, 100);
//    assert(status == SUCCESS);
//    show_list(p_list);
//
//    status = insert_before(p_list, 0, 200);
//    assert(status == SUCCESS);
//    show_list(p_list);
//
//    status = get_start(p_list, &data);
//    assert(status == SUCCESS);
//    printf("Start Data = %d\n", data);
//    show_list(p_list);
//
//    status = get_end(p_list, &data);
//    assert(status == SUCCESS);
//    printf("End Data = %d\n", data);
//    show_list(p_list);
//
//    status = pop_start(p_list, &data);
//    assert(status == SUCCESS);
//    printf("Start Data = %d\n", data);
//    show_list(p_list);
//
//    status = pop_end(p_list, &data);
//    assert(status == SUCCESS);
//    printf("End Data = %d\n", data);
//    show_list(p_list);
//
//    status = remove_start(p_list);
//    assert(status == SUCCESS);
//    show_list(p_list);
//
//    status = remove_end(p_list);
//    assert(status == SUCCESS);
//    show_list(p_list);
//
//    status = remove_data(p_list, -100);
//    assert(status == LIST_DATA_NOT_FOUND);
//
//    status = remove_data(p_list, 0);
//    assert(status == SUCCESS);
//    show_list(p_list);
//
//    if (is_list_empty(p_list) == FALSE)
//        puts("List is not empty now");
//
//    printf("length = %d\n", get_length(p_list));
//
//    destroy_list(&p_list);
//    assert(p_list == NULL);
//}

//void graph_client()
//{
//    std::vector<std::pair<int, int>> edges;
//    edges.push_back(std::make_pair(0, 1));
//    edges.push_back(std::make_pair(0, 4));
//    edges.push_back(std::make_pair(1, 2));
//    edges.push_back(std::make_pair(1, 3));
//    edges.push_back(std::make_pair(1, 4));
//    edges.push_back(std::make_pair(2, 3));
//    edges.push_back(std::make_pair(3, 4));
//    Graph graph(6, edges);
//    graph.PrintGraph();
//}

void bst_client(void)
{
    dsa::unique_ptr<dsa::BST> b;
    dsa::BST* root = NULL;
    root = b->InsertItr(root, 50);
    b->InsertItr(root, 30);
    b->InsertItr(root, 20);
    b->InsertItr(root, 40);
    b->InsertItr(root, 70);
    b->InsertItr(root, 60);
    b->InsertItr(root, 80);

    b->InorderItr(root);
    std::cout << std::endl;
    b->DeleteNode(root, 60);
    b->InorderItr(root);
    std::cout << std::endl;
    b->PreorderItr(root);
    std::cout << std::endl;
    b->PostorderItr(root);
    std::cout << std::endl;
    std::cout << heightOfTree(root) << std::endl;
}

void unique_ptr_demo_1()
{
    dsa::unique_ptr<int> pu1;
    if (pu1.get() == 0)
        std::cout << " pu1 contains null" << std::endl;

    dsa::unique_ptr<int> pu2(new int(500));
    printf("*pu2 : %d\n", *pu2);

    pu2 = nullptr;
    if (pu2.get() == 0)
        printf("pu2 contains null\n");

    //release()
    dsa::unique_ptr<int> pu3(new int(600));
    int* p_int = pu3.release();

    printf("*p_int : %d\n", *p_int);
    if (pu3.get() == 0)
        printf("Pu3 contains null\n");

    delete p_int;
    p_int = 0;

    //reset()
    dsa::unique_ptr<int> pu4(new int(700));
    pu4.reset();
    if (pu4.get() == 0)
        printf("Pu4 contains null\n");

    dsa::unique_ptr<int> pu5(new int(800));
    int* p_int1 = pu5.release();
    pu5.reset(p_int1);
    if (pu5.get() != 0)
        printf("pu5 is not null");
}
void shared_ptr()
{
    dsa::shared_ptr<int> pint_1(new int(10));
    dsa::shared_ptr<int> pint_2(pint_1);

    std::cout << "*pint_1 = " << *pint_1 << std::endl;
    std::cout << "*pint_2 = " << *pint_2 << std::endl;
    std::cout << "Ref count : " << pint_2.use_count() << std::endl;

    int* pi = pint_2.get();
    std::cout << "*pi = " << *pi << std::endl;

    dsa::shared_ptr<int> pint_3 = dsa::make_shared(100);
    std::cout << "*pint_3 = " << *pint_3 << std::endl;
}
int main()
{
    unsigned int i = 1;
    char* c = (char*)&i;
    //std::vector<int> vect{ 2,8,5,1,3,7,4,6,9,0 };
    std::stack<int> vect({ 2, 8, 5, 1, 3, 7, 4, 6, 9, 0 });
    if (*c)
        std::cout << "Little endian Machine\n";
    else
        std::cout << "Big endian Machine\n";
    Entity entity("Dipak");
    entity.PrintName();
    string apple = "Apple";
    string dest;
    std::cout << "Apple : ";
    apple.Print();
    std::cout << "\nDest : ";
    dest.Print();
    dest = std::move(apple);
    std::cout << "Apple : ";
    apple.Print();
    std::cout << "\nDest : ";
    dest.Print();

    //unique_ptr_demo_1();
    //shared_ptr();
    sort(vect);
    //std::cout << "Before Delete " << std::endl;
    //for (int i=0; !vect.empty(); i++)
    //{
    //    std::cout << vect.top() << std::endl;
    //    vect.pop();
    //}
    deleteStackElement(vect, 4);
    std::cout << "After Deleting " << std::endl;
    reverseStack(vect);
    for (int i = 0; !vect.empty(); i++)
    {
        std::cout << vect.top() << std::endl;
        vect.pop();
    }
    towerOfHonoi(3, 1, 2, 3);
    std::cout << kthGrammer(4, 5) << std::endl;;
    std::string op = "";
    std::string ip = "1234";
    stringSubset(ip, op);
    std::cout << std::endl;
    op.push_back(ip[0]);
    ip.erase(ip.begin() + 0);
    stringSubsetWithSpace(ip, op);
    ip = "abcd";
    op = "";
    stringSubsetWithCaseChange(ip, op);
    ip = "a1b2";
    op = "";
    stringSubsetWithCaseChangeWithNum(ip, op);
    op = "";
    balancedParanthesis(op, 2, 2);
    op = "";
    binaryNumberWithPrefix(op, 0, 0, 4);
    std::vector<int> vector(40);
    std::iota(vector.begin(), vector.end(), 1);
    JosephusProblem(vector, 6, 0);
    vector = { 2, 8, 5, 1, 3, 7, 4, 6, 9, 0 };
    std::cout << std::endl << kthMaxElement(vector, 5);
    std::cout << std::endl << kthMinElement(vector, 5);
    std::cout << "\nMin Heap" << std::endl;
    kMaxElement(vector, 5);
    std::cout << std::endl; 
    std::cout << "\nMax Heap" << std::endl;
    vector = { 8, 5, 1, 3, 7, 6, 9, 0 };
    kMinElement(vector, 5);
    kClosestElement(vector, 3);
    vector = { 1, 1, 1, 3, 4, 7, 7, 2, 2, 2 };
    SortAsFreqNumbers(vector);
    TopFreqNumbers(vector);
    std::vector<std::pair<int, int>> points;
    points = { std::make_pair(0,5), 
        std::make_pair(-3,4), 
        std::make_pair(5,6), 
        std::make_pair(2,3), 
        std::make_pair(1,2), 
        std::make_pair(0,1),
        std::make_pair(5,1) };
    KPointsClosestFromOrigin(points, 3);
    vector = { 1, 2, 3, 4, 5};
    LowestCostForRope(vector);
    vector = { 4, 5, 2, 10, 8 };
    NearestGreaterToRight(vector);
    NearestSmallerToRight(vector);
    NearestGreaterToLeft(vector);
    NearestSmallerToLeft(vector);
    StockSpanProblem(vector);
    vector = { 6, 2, 5, 4, 5, 1, 6};
    AreaOfHisto(vector);
    std::vector<std::vector<int>> matrix = {
    {0, 1, 1, 0},
    {1, 1, 1, 1},
    {1, 1, 1, 1},
    {0, 1, 1, 0},
    };
    AreaOfBinaryMatrix(matrix, 4, 4);
    vector = { 3, 0, 0, 2, 0, 4};
    RainWaterTrapping(vector);
    //bst_client();
    //printNumberWithRecurssion(10);
    //std::cout << fibbonacciSeries(9) << std::endl;
    //std::cout << factorial(10);
    MinStack mstk;
    mstk.push(2);
    mstk.push(1); 
    mstk.push(3);
    mstk.push(5);
    mstk.push(0);
    mstk.push(4);
    mstk.pop();
    int m = mstk.getMin();

    MinStackOderOfOne mstkoone;
    mstkoone.push(2);
    mstkoone.push(1);
    mstkoone.push(3);
    mstkoone.push(5);
    mstkoone.push(0);
    mstkoone.push(4);
    mstkoone.pop();
    int m1 = mstkoone.getMin();
    mstkoone.pop();
    mstkoone.pop();
    mstkoone.pop();
    mstkoone.pop();
    mstkoone.pop();
    vector = { 1, 2, 3, 4, 5, 6 };
    int k = BinarySearch(vector, 5);
     k = BinarySearch(vector, 8);
     vector = { 1, 2, 3, 4, 5, 6 };
     std::reverse(vector.begin(), vector.end());
     k = BinarySearchRev(vector, 5);
     k = BinarySearchRev(vector, 3);
     vector = { 4, 5, 6, 7, 1, 2, 3,};
     k = NumberOfRotationInSortedArray(vector);
     k = FindNumberInSortedRotatedArray(vector, 7);
     std::cout << " Maximum sum : " << MaximumSumOfSubArray(vector, 2);
     std::string str = "abaababaa";
     std::string pattern = "ab";
     k =CountOfAnagram(str, pattern);
     vector = { -4, -5, -6, 7, 1, 2, 3, };
     std::vector<int> newvect = FirstNegativeNumberInWindow(vector, 3);
     vector = { 4, 1, 1, 2, 2, 1, 3, 1, 2, 3, 1, 1, 1, 1, 1, 1 };
     newvect = MaxOfSubArray(vector, 3);
     SumOfLargestSubArray(vector, 6);
    return 0;
}

//Little endian Machine
//20 30 40 50 60 70 80
//50 30 20 40 70 60 80
//20 40 30 60 80 70 50
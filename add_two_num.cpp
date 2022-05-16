
#include <iostream>
#include<vector>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	istNode(int x, ListNode* next) : val(x), next(next) {}
	
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* node = new ListNode(0);
    ListNode* oof = node;
    int carry = 0;
    while (l1->next != nullptr || l2->next != nullptr)
    {
        int sum = 0;
        if (l1->next != nullptr && l2->next == nullptr)
        {
            sum = l1->val;
            l1 = l1->next;
        }
        else if (l2->next != nullptr && l1->next == nullptr)
        {
            sum = l2->val;
            l2 = l2->next;
        }
        else
        {
            sum = l1->val + l2->val;
            l1 = l1->next;
            l2 = l2->next;
        }
        sum += carry;
        carry = 0;
        oof->val = (sum != 0) ? sum % 10 : 0;
        carry = floor(sum / 10);
        ListNode* p = new ListNode(0);
        oof->next = p;
        oof = oof->next;
    }
    if (carry != 0)
    {
        ListNode* p = new ListNode(carry);
        oof->next = p;
    }
    return node;
}

int getSum(int a, int b) {
    int A[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
    int B[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
    int* Ab = A;
    int* Bb = B;
    for (int i = 0; i < 10;i++)
    {
        if (a % 2 == 1)
            Ab[i] = 1;
        if (b % 2 == 1)
            Bb[i] = 1;
        a /= 2;
        b /= 2;
    }
    if (a < 0)
        Ab = convert(Ab);
    if (b < 0)
        Bb = convert(Bb);

    int carry = 0;
    int C[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
    int* Cb = C;
    for (int i = 0;i < 11;i++)
    {
        int temp = 0;
        if ((Ab[i] && Bb[i]) || (((Ab[i] || Bb[i]) && carry)))
        {
            if (Ab[i] && Bb[i] && carry)
                Cb[i] = 1;
            else
                Cb[i] = 0;
            temp = 1;
        }
        else if (Ab[i] || Bb[i] || carry)
            Cb[i] = 1;
        carry = temp;
    }
    int sign = 1;
    if (Cb[10] == 1)
    {
        Cb = convert(Cb);
        sign = -sign;
    }
    int sum = 0;
    for (int i = 0; i < 10; i++)
        sum += pow((Cb[i] * 2), i);
    return sum * sign;

}

int* convert(int* a)
{
    int carry = 1;
    for (int i = 0;i < 11;i++)
    {
        a[i] = (a[i] == 1) ? 0 : 1;
        if (a[i] && carry)
        {
            carry = 1;
            a[i] = 1;
        }
        else if (a[i] || carry)
        {
            a[i] = 1;
            carry = 0;
        }
        else
            carry = 0;
    }
    return a;
}
int main()
{
    cout << getSum(20, 30);
}

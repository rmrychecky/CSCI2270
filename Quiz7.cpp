
#include <iostream>
#include <iomanip> 
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

// void fun(int n){
//     if(n > 0) {
//         fun(n-1);
//         printf("%d ", n);
//         fun(n-1);
//     }
//     else
//         return;
// }
// int main(){
//     fun(3);
//     return 0;
// }



int findSum(TreeNode * root, int depth)
{
    if(root != NULL)
    {
        int rightSum = findSum(root->right, depth + 1);
        int leftSum = findSum(root->left, depth + 1);
        cout << root->key;
        if (depth != 0)
        {
            cout << " ";
        }
        return rightSum + leftSum + root->key;
    }
    else
       return 0;
}
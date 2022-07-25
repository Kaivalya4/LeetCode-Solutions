Method1( Use of extra space ) : In Rotation First Column becomes first row i.e. all elements of first column will be in first row (starting from below that is bottom most element becomes first element , second bottom element becomes second element and so on..)
1                                 3 2 1
2          -------- >
3
​
Similar pattern with other column . This pattern can be achieved using Two loops :
for (int j = 0; j < N; j++)
{
for (int i = N - 1; i >= 0; i--)
cout << arr[i][j] << " ";
cout << '\n';
}
Method2 ( moving forward each element)  :  push elements of following position one forward (0,0) -> (1,n) -> (n,n) -> (n,1) -> (0,0) .
Similarly other elements of outer loops . Then do same for inner loop.
See first accepted solution.
Method3 : Transpose and rotate each row ( use pen and paper and then see second accpeted solution)
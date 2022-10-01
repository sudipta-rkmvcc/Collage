#include <iostream>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
using namespace std;
void printArray(int arr[], int size)
{
    cout << "The Array is :\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
    cout << endl;
}
void Merge(int arr[], int l, int mid, int h)
{
    int n1 = mid - l + 1;
    int n2 = h - mid;
    int a[n1], b[n2];
    for (int i = 0; i < n1; i++)
        a[i] = arr[i + l];
    for (int i = 0; i < n2; i++)
        b[i] = arr[i + mid + 1];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
            arr[k++] = a[i++];
        else
            arr[k++] = b[j++];
    }
    while (i < n1)
        arr[k++] = a[i++];
    while (j < n2)
        arr[k++] = b[j++];
}
void MergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        MergeSort(arr, l, mid);
        MergeSort(arr, mid + 1, h);
        Merge(arr, l, mid, h);
    }
}
int pivotIndex(int arr[], int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    int temp;
    while (i < j)
    {
        while (pivot >= arr[i])
            i++;
        while (pivot < arr[j])
            j--;
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;
    return j;
}
void QuickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int pi = pivotIndex(arr, l, h);
        QuickSort(arr, l, pi - 1);
        QuickSort(arr, pi + 1, h);
    }
}
void Heapify(int arr[], int size, int i)
{
    int large = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < size && arr[l] > arr[large])
        large = l;
    if (r < size && arr[r] > arr[large])
        large = r;
    if (large != i)
    {
        int temp = arr[large];
        arr[large] = arr[i];
        arr[i] = temp;
        Heapify(arr, size, large);
    }
}
void HeapSort(int arr[], int size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
        Heapify(arr, size, i);
    for (int i = size - 1; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        Heapify(arr, i, 0);
    }
}
void CountSort(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    int *count = (int *)calloc(sizeof(int), (max + 1));

    for (int i = 0; i < size; i++)
        count[arr[i]]++;

    for (int i = 1; i < max + 1; i++)
        count[i] += count[i - 1];

    int output[size];

    for (int i = size - 1; i >= 0; i--)
        output[--count[arr[i]]] = arr[i];

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}
void CS(int arr[], int size, int pos)
{
    int count[10] = {0};

    for (int i = 0; i < size; i++)
        count[(arr[i] / pos) % 10]++;

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    int output[size];

    for (int i = size - 1; i >= 0; i--)
        output[--count[(arr[i] / pos) % 10]] = arr[i];

    for (int i = 0; i < size; i++)
        arr[i] = output[i];
}
void RadixSort(int arr[], int size)
{
    int max = arr[0];
    for (int i = 1; i < size; i++)
        if (max < arr[i])
            max = arr[i];

    for (int pos = 1; max / pos > 0; pos = pos * 10)
        CS(arr, size, pos);
}
void BubbleSort(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void SelectionSort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
            if (arr[min] > arr[j])
                min = j;
        if (min != i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}
void BFS(int **AdjMatrix, int vertex)
{
    int *visit = (int *)calloc(sizeof(int), vertex);
    queue<int> q;
    q.push(0);
    cout << "The BFS Travertion is:\n";
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        if (!visit[v])
        {
            cout << v << "\t";
            visit[v] = 1;
        }
        for (int i = 0; i < vertex; i++)
            if (!visit[i] && AdjMatrix[v][i])
                q.push(i);
    }
    cout << endl;
}
void DFS(int **AdjMatrix, int vertex)
{
    int *visit = (int *)calloc(sizeof(int), vertex);
    stack<int> s;
    s.push(0);
    cout << "The DFS Travertion is:\n";
    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        if (!visit[v])
        {
            cout << v << "\t";
            visit[v] = 1;
        }
        for (int i = 0; i < vertex; i++)
            if (AdjMatrix[v][i] && !visit[i])
                s.push(i);
    }
    cout << "\n";
}
void primesAlgorithm(int **AdjMatrix, int vertex)
{
    int i = 0;
    int *visit = (int *)calloc(sizeof(int), vertex);
    visit[i] = 1;
    int cost = 0;
    while (i < vertex - 1)
    {
        int x = 0;
        int y = 0;
        int min = 99999;
        for (int v = 0; v < vertex; v++)
        {
            if (visit[v])
            {
                for (int j = 0; j < vertex; j++)
                {
                    if (AdjMatrix[v][j] && !visit[j])
                    {
                        if (min > AdjMatrix[v][j])
                        {
                            x = v;
                            y = j;
                            min = AdjMatrix[v][j];
                        }
                    }
                }
            }
        }
        i++;
        cost += min;
        visit[y] = 1;
        cout << x << " <---" << min << "---> " << y << endl;
    }
    cout << "The cost is = " << cost << endl;
}
int NaiveAlgorithm(char str[], char patt[])
{
    int m = strlen(patt);
    int n = strlen(str);
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && patt[j] == str[i + j])
            j++;
        if (j == m)
        {
            return i;
        }
    }
    return -1;
}
int f[] = {0};
void preFix(char patt[])
{
    int i = 1;
    int j = 0;
    int m = strlen(patt);
    while (i < m)
    {
        if (patt[i] == patt[j])
            f[i++] = j++;
        else if (j > 0)
            j = f[j--];
        else
            f[i++] = 0;
    }
}
int KMP(char str[], char patt[])
{
    int m = strlen(patt);
    int n = strlen(str);
    int i = 0;
    int j = 0;
    preFix(patt);
    while (i < n)
    {
        if (patt[j] == str[i])
        {
            if (j == m - 1)
                return i - j;
            else
            {
                i++;
                j++;
            }
        }
        else if (j > 0)
            j = f[j--];
        else
            i++;
    }
    return -1;
}
int memo[2024][2024];
int LCS(int i, int j, char str1[], char str2[])
{

    if (i == 0 || j == 0)
        return 0;

    if (memo[i][j])
        return memo[i][j];

    int ans1 = LCS(i - 1, j, str1, str2);
    int ans2 = LCS(i, j - 1, str1, str2);

    int ans = max(ans1, ans2);
    ans = max(ans, (LCS(i - 1, j - 1, str1, str2) + (str1[i] == str2[j])));

    memo[i][j] = ans;
    return memo[i][j];
}
void InsertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && key < arr[j])
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void ShellSort(int arr[], int size)
{
    int m = size / 2;
    while (m > 0)
    {
        for (int i = m; i < size; i++)
        {
            for (int j = i - m; j >= 0; j--)
            {
                if (arr[j] > arr[j + m])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + m];
                    arr[j + m] = temp;
                }
            }
        }
        m /= 2;
    }
}
int KthOrder(int arr[], int l, int h, int i)
{
    if (l == h)
        return arr[l];
    int k = pivotIndex(arr, l, h);
    if (k == i)
        return arr[k];
    else if (k < i)
        return (KthOrder(arr, k + 1, h, i));
    else
        return (KthOrder(arr, l, k - 1, i));
}
int main()
{
    int arr[] = {71, 74, 61, 68, 56, 52, 95, 65, 37, 0};
    printArray(arr, 10);
    cout << "Index 7 value = " << KthOrder(arr, 0, 9, 7) << endl;
    BubbleSort(arr, 10);
    printArray(arr, 10);

    char str[] = "Sudipta Sarkar";
    char patt[] = "Sarkar";
    cout << "The Matching Index [KMP] = " << KMP(str, patt) << "\t [Naive] = " << NaiveAlgorithm(str, patt) << endl;

    char str1[] = "ABCDEFGHIJKLMNOPQRS";
    char str2[] = "ABMTWXZQA";
    cout << "LCS = " << LCS(strlen(str1), strlen(str2), str1, str2) << endl;

    int vertex;
    int edge;
    int weight;

    cout << "Enter the No of Vertex = ";
    cin >> vertex;
    cout << "Enter the No of Edge = ";
    cin >> edge;

    int **AdjMatrix = (int **)calloc(sizeof(int *), vertex);
    for (int i = 0; i < vertex; i++)
        AdjMatrix[i] = (int *)calloc(sizeof(int), vertex);

    cout << "Enter the Details of Vertex and Edge along with thire weights :\n";

    for (int i = 0; i < edge; i++)
    {
        int v;
        int u;
        int w;
        cout << "Enter Edge Along With Weight [" << i + 1 << "]" << endl;
        cin >> v >> u >> w;
        AdjMatrix[v][u] = w;
        AdjMatrix[u][v] = w;
    }

    BFS(AdjMatrix, vertex);
    DFS(AdjMatrix, vertex);
    primesAlgorithm(AdjMatrix, vertex);
    return 0;
}

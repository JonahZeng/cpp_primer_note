    # 多维数组和指向多维数组的指针
    --------------------------
    如下代码：
    ```c++
    #include <iostream>\n
    using std::endl;
    using std::cout;
    
    int main(void)
    {
        int m_arr[3][4] = { {0,1,2,3},
                            {4,5,6,7},
                            {8,9,10,11}};
        int (*m_pt)[4] = m_arr;//定义指向二维数组的指针
        for(int i = 0; i!=3; i++)
        {
            for(int j=0; j!=4; j++)
                cout<<m_pt[i][j]<<endl;
        }
        return 0;
    }
    ```

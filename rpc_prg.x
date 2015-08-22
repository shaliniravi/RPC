struct echo {
       char a[100];
};

struct sort_arr{
   int b[100];
   int number_sort;
};

struct multiply{
int row1;
int row2;
int col1;
int col2;
int matrixA[100];
int matrixB[100];
};

struct result_mat{
int matrixC[100];
};


struct time_char{
char T[100];
};

program RPC_PRG {
        version RPC_PRG_VERS {             
                time_char time_func(int id) = 1;
                echo echo_message(echo) = 2;
                string  listFiles(int id) = 3;
                sort_arr sorting(sort_arr) = 4;
                result_mat multiplier(multiply) = 5;                           
        } = 1;
} = 0x23451111;

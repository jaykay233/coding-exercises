//SPMV_串行CSR
for(int row=0;row<num_rows;row++){
    float dot =0 ;
    int row_start = row_ptr[row];
    int row_end = row_ptr[row+1];
    for(int elem = row_start;elem<row_end;elem++){
        dot += data[elem] * x[col_index[elem]]
    }
    y[row] += dot
}


//SPMV_并行CSR
__global__ void spmv_csr(int num_rows,float *data,int* col_index,int *row_ptr,float *x,float *y){
    int row = blockidx.x * blockDim.x + threadIdx.x;
    if(row<num_rows){
        float dot =0;
        int row_start = row_ptr[row];
        int row_end =row_ptr[row+1];
        for(int elem=row_start;elem<row_end;elem++){
            dot+=data[elem]*x[col_index[elem]];
        }
    }
    y[row] = dot;
}

//SPMV_CSR优化方案

//##########
//填充与转置
//ELL存储格式
__global__ void SPMVELL(int num_rows,float* data,int* col_index,int num_elem,float* x,float* y){
    int row = blockIdx.x * blockDim.x + threadIdx.x;
    if(row<num_rows){
        float dot =0 ;
        for(int i=0;i<num_elem;i++){
            dot += data[row+i*num_rows]*x[col_index[row+i*num_rows]];
        }
    }
    y[row] += dot;
}


//##########
//混合填充



//##########
//排序划分规则化

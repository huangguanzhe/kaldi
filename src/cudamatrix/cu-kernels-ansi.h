// cudamatrix/cu-kernels-ansi.h

// Copyright 2009-2012  Karel Vesely
//                2013  Johns Hopkins University (author: Daniel Povey)
//                2013  Hainan Xu
//                2013  Xiaohui Zhang
//           2013-2015  Guoguo Chen

// See ../../COPYING for clarification regarding multiple authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//  http://www.apache.org/licenses/LICENSE-2.0
//
// THIS CODE IS PROVIDED *AS IS* BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION ANY IMPLIED
// WARRANTIES OR CONDITIONS OF TITLE, FITNESS FOR A PARTICULAR PURPOSE,
// MERCHANTABLITY OR NON-INFRINGEMENT.
// See the Apache 2 License for the specific language governing permissions and
// limitations under the License.




#ifndef KALDI_CUDAMATRIX_CU_KERNELS_ANSI_H_
#define KALDI_CUDAMATRIX_CU_KERNELS_ANSI_H_

#include "cudamatrix/cu-matrixdim.h"

#if HAVE_CUDA == 1
extern "C" {

/*********************************************************
 * int32 CUDA kernel calls (no template wrapper)
 */
void cuda_int32_set_const(dim3 Gr, dim3 Bl, int32_cuda *mat, int32_cuda value, MatrixDim d);
void cuda_int32_add(dim3 Gr, dim3 Bl, int32_cuda *mat, int32_cuda value, MatrixDim d);



/*********************************************************
 * float CUDA kernel calls
 */

/*
 * CuMatrix
 */
void cudaF_copy_upp_low(dim3 Gr, dim3 Bl, float* A, MatrixDim dimA);
void cudaF_copy_low_upp(dim3 Gr, dim3 Bl, float* A, MatrixDim dimA);
void cudaF_add_diag_vec_mat(dim3 Gr, dim3 Bl, float alpha, float *mat, MatrixDim mat_dim,
                            const float *vec, const float *mat2, int mat2_row_stride,
                            int mat2_col_stride, float beta);
void cudaF_copy_from_tp_trans(dim3 Gr, dim3 Bl, float* A, const float* B, MatrixDim dmat);
void cudaFD_copy_from_tp_trans(dim3 Gr, dim3 Bl, float* A, const double* B, MatrixDim dmat);
void cudaF_copy_from_tp(dim3 Gr, dim3 Bl, float* A, const float* B, MatrixDim dmat);
void cudaFD_copy_from_tp(dim3 Gr, dim3 Bl, float* A, const double* B, MatrixDim dmat);
void cudaF_apply_exp(dim3 Gr, dim3 Bl, float* mat, MatrixDim d);
void cudaF_apply_pow(dim3 Gr, dim3 Bl, float* mat, float power, MatrixDim d);
void cudaF_apply_pow_abs(dim3 Gr, dim3 Bl, float* mat, float power, bool include_sign,  MatrixDim d);
void cudaF_apply_heaviside(dim3 Gr, dim3 Bl, float* mat, MatrixDim d);
void cudaF_apply_floor(dim3 Gr, dim3 Bl, float* mat, float floor_val, MatrixDim d);
void cudaF_copy_cols(dim3 Gr, dim3 Bl, float* dst, const float* src, const MatrixIndexT_cuda* reorder, MatrixDim dst_dim, int src_stride);
void cudaF_add_cols(dim3 Gr, dim3 Bl, float* dst, const float* src, const MatrixIndexT_cuda* reorder, MatrixDim dst_dim, int src_stride);
void cudaF_copy_rows(dim3 Gr, dim3 Bl, float* dst, const float* src, const MatrixIndexT_cuda* reorder, MatrixDim dst_dim, int src_stride);
void cudaF_copy_rows_direct(dim3 Gr, dim3 Bl, float* dst, const float* const* src, MatrixDim dst_dim);
void cudaF_copy_to_rows_direct(dim3 Gr, dim3 Bl, float* const* dst, const float* src, MatrixDim src_dim);
void cudaF_add_rows(dim3 Gr, dim3 Bl, float alpha, float* dst, const float* src, const MatrixIndexT_cuda* reorder, MatrixDim dst_dim, int src_stride);
void cudaF_add_rows_direct(dim3 Gr, dim3 Bl, float alpha, float* dst, const float* const* src, MatrixDim dst_dim);
void cudaF_add_to_rows_direct(dim3 Gr, dim3 Bl, float alpha, float* const* dst, const float* src, MatrixDim src_dim);
void cudaF_apply_ceiling(dim3 Gr, dim3 Bl, float* mat, float ceiling_val, MatrixDim d);
void cudaF_set_diag(int Gr, int Bl, float* mat, float value, MatrixDim d);
void cudaF_set_diag_packed(int Gr, int Bl, float* mat, float value, int dim);
void cudaF_add_diag_packed(int Gr, int Bl, float* mat, float value, int dim);
void cudaF_set_const(dim3 Gr, dim3 Bl, float *mat, float value, MatrixDim d);
void cudaF_set_zero_above_diag(dim3 Gr, dim3 Bl, float* mat, MatrixDim d);
void cudaF_add(dim3 Gr, dim3 Bl, float *mat, float value, MatrixDim d);
void cudaF_add_vec2(dim3 Gr, dim3 Bl, float* mat, const float* vec, const float alpha, int dim);
void cudaF_scale_diag_packed(int Gr, int Bl, float* mat, float value, int dim);
void cudaF_scale(dim3 Gr, dim3 Bl, float *mat, float value, MatrixDim d);
void cudaF_apply_log(dim3 Gr, dim3 Bl, float *mat, MatrixDim d);
void cudaF_mul_elements(dim3 Gr, dim3 Bl, float *mat, const float *A, MatrixDim dst_d, int src_stride);
void cudaF_div_elements(dim3 Gr, dim3 Bl, float *mat, const float *A, MatrixDim dst_d, int src_stride);
void cudaF_max(dim3 Gr, dim3 Bl, float *mat, const float *A, MatrixDim dst_d, int src_stride);
void cudaF_mul_cols_vec(dim3 Gr, dim3 Bl, float *mat, const float *scale, MatrixDim d);
void cudaF_mul_rows_vec(dim3 Gr, dim3 Bl, float *mat, const float *scale, MatrixDim d);
void cudaF_mul_rows_group_mat(dim3 Gr, dim3 Bl, float *y, const float *x, MatrixDim d, int src_stride, int group_size);
void cudaF_calc_pnorm_deriv(dim3 Gr, dim3 Bl, float *y, const float *x1, const float *x2,  MatrixDim d, int src_stride, int group_size, float power);
void cudaF_diff_group_pnorm(dim3 Gr, dim3 Bl, float *id, const float *iv,
                            const float *ov, const float* od, MatrixDim id_dim,
                            int iv_stride, int ov_stride, int od_stride,
                            int group_size, float power);
void cudaF_calc_group_max_deriv(dim3 Gr, dim3 Bl, float *y, const float *x1, const float *x2,  MatrixDim d, int src_stride, int group_size);
void cudaF_div_rows_vec(dim3 Gr, dim3 Bl, float *mat, const float *vec_div, MatrixDim d);
void cudaF_add_mat(dim3 Gr, dim3 Bl, float alpha, const float *src, float *dst, MatrixDim d, int src_stride, int A_trans);
void cudaF_add_mat_blocks(dim3 Gr, dim3 Bl, float alpha, const float *src, int32_cuda num_row_blocks, int32_cuda num_col_blocks, float *dst, MatrixDim d, int src_stride, int A_trans);
void cudaF_add_mat_mat_div_mat(dim3 Gr, dim3 Bl, const float *A, const float *B, const float *C, float *dst, MatrixDim d, int stride_a, int stride_b, int stride_c);
void cudaF_add_vec_to_cols(dim3 Gr, dim3 Bl, float alpha, const float *col, float beta, float *dst, MatrixDim d);
void cudaF_add_vec_to_rows(dim3 Gr, dim3 Bl, float alpha, const float *row, float beta, float *dst, MatrixDim d);
void cudaF_add_mat_diag_vec(dim3 Gr, dim3 Bl, float alpha, float *mat, MatrixDim mat_dim, const float *mat2, int mat2_row_stride, int mat2_col_stride, const float *vec, float beta);
void cudaF_add_mat_mat_elements(dim3 Gr, dim3 Bl, float *data, const float *srcA_data, const float *srcB_data, MatrixDim dim, int srcA_stride, int srcB_stride, float alpha, float beta);
/*
 * CuVector
 */
void cudaF_max_mat_cols(int Gr, int Bl, float* result, const float* mat, const MatrixDim d);
void cudaF_min_mat_cols(int Gr, int Bl, float* result, const float* mat, const MatrixDim d);
void cudaF_sum_mat_cols(int Gr, int Bl, float* result, const float* mat, const MatrixDim d);
void cudaF_replace_value(int Gr, int Bl, float *v, int dim, float orig, float changed);
void cudaF_set_bias_params(int Gr, int Bl, float* v, const float* a, float param_1, float param_2, float param_3, int* flag, int dim);
void cublas_copy_kaldi_fd(int Gr, int Bl, int n, const float* x,
    int incx, double* y, int incy);
void cublas_copy_kaldi_df(int Gr, int Bl, int n, const double* x,
    int incx, float* y, int incy);
void cudaF_vec_mul_elements(int Gr, int Bl, float* v, const float* a, int dim);
void cudaF_vec_soft_max(int Gr, int Bl, float* v, int dim);
void cudaF_vec_min(int Gr, int Bl, const float* v, float* value, int dim, int inc);
void cudaF_vec_max(int Gr, int Bl, const float* v, float* value, int dim, int inc);
void cudaF_trace_mat_mat_trans(dim3 Gr, dim3 Bl, const float* A, const float* B, MatrixDim dA, int B_stride, float* value);
void cudaF_trace_mat_mat(dim3 Gr, dim3 Bl, const float* A, const float* B, MatrixDim dA, int B_stride, float* value);
void cudaF_add_diag_mat_mat_MNT(int Gr, int Bl, const float alpha,
                                const float* M, const MatrixDim dim_M,
                                const float* N, const int stride_N,
                                const float beta, float* v);
void cudaF_add_diag_mat_mat_MTN(dim3 Gr, dim3 Bl, const float alpha,
                                const float* M, const int strid_M,
                                const float* N, const MatrixDim dim_N,
                                const float beta, float* v);
void cudaF_add_diag_mat_mat_MN(dim3 Gr, dim3 Bl, const float alpha,
                               const float* M, const int strid_M,
                               const float* N, const MatrixDim dim_N,
                               const float beta, float* v);
void cudaF_add_vec_vec(int Gr, int Bl, float alpha, float* v, const float* x, const float* y, float beta, int dim);
void cudaF_copy_col_from_mat_df(int Gr, int Bl, double* v, int col, const float* mat, MatrixDim dmat, int dim);
void cudaF_copy_col_from_mat_fd(int Gr, int Bl, float* v, int col, const float* mat, MatrixDim dmat, int dim);
void cudaF_vec_sum(int Gr, int Bl, float* v, float* value, int dim, int inc);
void cudaF_vec_copy_diag_from_packed(int Gr, int Bl, float *dst, const float *src, int dim);
void cudaF_vec_apply_floor(int Gr, int Bl, float* v, float floor_val, float* num, int dim);
void cudaF_vec_apply_ceiling(int Gr, int Bl, float* v, float ceiling_val, float* num, int dim);
void cudaF_vec_apply_exp(int Gr, int Bl, float* v, int dim);
void cudaF_vec_apply_log(int Gr, int Bl, float* v, float* flag, int dim);
void cudaF_trace(int Gr, int Bl, float* mat, float* value, int dim);
void cudaF_invert_elements(dim3 Gr, dim3 Bl, float *data, MatrixDim d);
// Note: B_trans is nonzero if B is transposed.
void cudaF_add_mat_blockmat(dim3 Gr, dim3 Bl, float *data, MatrixDim d, const float *Adata,
                            int A_num_rows, int A_num_cols, int A_row_stride, int A_col_stride,
                            const CuBlockMatrixData *B_cu_data, int B_num_blocks,
                            float alpha, float beta, int B_trans);
void cudaF_block_add_mat_mat(dim3 Gr, dim3 Bl, CuBlockMatrixData *B_cu_data, int num_blocks,
                             const float *C_data, int C_num_cols, int C_row_stride, int C_col_stride,
                             const float *D_data, int D_row_stride, int D_col_stride,
                             float alpha, float beta);
/*
 * cu::
 */
void cudaF_softmax_reduce(size_t Gr, size_t Bl, float *y, const float *x, MatrixDim d, int src_stride);
void cudaF_log_softmax_reduce(size_t Gr, size_t Bl, float *y, const float *x, MatrixDim d, int src_stride);
void cudaF_soft_hinge(dim3 Gr, dim3 Bl, float *y, const float *x, MatrixDim d, int src_stride);
void cudaF_group_pnorm(dim3 Gr, dim3 Bl, float *y, const float *x, MatrixDim d, int src_stride, int group_size, float power);
void cudaF_group_spec_pnorm(dim3 Gr, dim3 Bl, float *y, const float *x,
                            MatrixDim d, int src_stride, int group_size,
                            float power);
void cudaF_group_max(dim3 Gr, dim3 Bl, float *y, const float *x, MatrixDim d, int src_stride, int group_size);
void cudaF_sigmoid(dim3 Gr, dim3 Bl, float *y, const float *x, MatrixDim d, int src_stride);
void cudaF_heaviside(dim3 Gr, dim3 Bl, float *y, const float *x, MatrixDim d, int src_stride);
void cudaF_diff_sigmoid(dim3 Gr, dim3 Bl, float *eout, const float *e, const float *y, MatrixDim d, int e_stride, int y_stride);
void cudaF_tanh(dim3 Gr, dim3 Bl, float *y, const float *x, MatrixDim d, int src_stride);
void cudaF_diff_tanh(dim3 Gr, dim3 Bl, float *eout, const float *e, const float *y, MatrixDim d, int e_stride, int y_stride);

void cudaF_regularize_l1(dim3 Gr, dim3 Bl, float *wei, float *grad, float l1, float lr, MatrixDim d, int stride_grad);
void cudaF_find_row_max_id(dim3 Gr, dim3 Bl, const float *mat, float *vec_val, int32_cuda *vec_id, MatrixDim d);
void cudaF_diff_xent(dim3 Gr, dim3 Bl, const int32_cuda *vec_tgt, float *mat_net_out, float *vec_log_post, MatrixDim d);
void cudaF_diff_softmax(dim3 Gr, dim3 Bl, float* x, const MatrixDim dim,
                        const float* value, const int value_stride,
                        const float* diff, const int diff_stride);
void cudaF_copy_rows_from_vec(dim3 Gr, dim3 Bl, float *mat_out, MatrixDim d_out, const float *v_in);

void cudaF_randomize(dim3 Gr, dim3 Bl, float *y, const float *x, const int32_cuda *copy_from, MatrixDim d_out, MatrixDim d_in);
void cudaF_splice(dim3 Gr, dim3 Bl, float *y, const float *x, const int32_cuda *off, MatrixDim d_out, MatrixDim d_in);
void cudaF_one(int Gr, int Bl, float* x, int dim);
void cudaF_copy(dim3 Gr, dim3 Bl, float *y, const float *x, const int32_cuda *copy_from, MatrixDim d_out, MatrixDim d_in);
void cudaF_copy_from_sp(dim3 Gr, dim3 Bl, const float* x, float* y, MatrixDim d_out);
void cudaF_take_lower(dim3 Gr, dim3 Bl, const float* x, float* y, MatrixDim d_in);
void cudaF_take_upper(dim3 Gr, dim3 Bl, const float* x, float* y, MatrixDim d_in);
void cudaF_take_mean(dim3 Gr, dim3 Bl, const float* x, float* y, MatrixDim d_in);
void cudaF_matrix_add_elements(dim3 Gr, dim3 Bl, float *data, MatrixDim dim, float alpha, MatrixElement<float>* x, int num_elements);
void cudaF_matrix_add_indexed_values(dim3 Gr, dim3 Bl, MatrixDim dim, float alpha, const Int32Pair* indices, const float* x, int s, float* data);
void cudaF_comp_obj_deriv(dim3 Gr,dim3 Bl, MatrixElement<float>* x, int s, const float* z, MatrixDim d, float* z2, MatrixDim d2, float* t);
void cudaF_sy_add_tr2(dim3 Gr, dim3 Bl, float alpha, float beta, const float* T, MatrixDim tdim,
                      float *S, MatrixDim sdim);
void cudaF_sum_column_ranges(dim3 Gr, dim3 Bl, float *data, MatrixDim dim,
                             const float *src_data, MatrixDim src_dim,
                             const Int32Pair *indices);
void cudaF_add_row_ranges(dim3 Gr, dim3 Bl, float *data, MatrixDim dim,
                          const float *src_data, MatrixDim src_dim,
                          const Int32Pair *indexes);
void cudaF_matrix_lookup(dim3 Gr, dim3 Bl, const float *data, MatrixDim dim,
                         const Int32Pair *indices, int indices_size,
                         float *output);

void cudaF_equal_element_mask(dim3 Gr, dim3 Bl, const float *mat1,
                              const float *mat2, float *mask, MatrixDim mat1_dim,
                              int mat2_stride, int mask_stride);

/*********************************************************
 * double CUDA kernel calls
 */

/*
 * CuMatrix
 */
void cudaD_copy_upp_low(dim3 Gr, dim3 Bl, double* A, MatrixDim dimB);
void cudaD_copy_low_upp(dim3 Gr, dim3 Bl, double* A, MatrixDim dimA);
void cudaD_add_diag_vec_mat(dim3 Gr, dim3 Bl, double alpha, double *mat, MatrixDim mat_dim,
                            const double *vec, const double *mat2, int mat2_row_stride,
                            int mat2_col_stride, double beta);
void cudaD_copy_from_tp_trans(dim3 Gr, dim3 Bl, double* A, const double* B, MatrixDim dmat);
void cudaDF_copy_from_tp_trans(dim3 Gr, dim3 Bl, double* A, const float* B, MatrixDim dmat);
void cudaD_copy_from_tp(dim3 Gr, dim3 Bl, double* A, const double* B, MatrixDim dmat);
void cudaDF_copy_from_tp(dim3 Gr, dim3 Bl, double* A, const float* B, MatrixDim dmat);
void cudaD_apply_exp(dim3 Gr, dim3 Bl, double* mat, MatrixDim d);
void cudaD_apply_pow(dim3 Gr, dim3 Bl, double* mat, double power, MatrixDim d);
void cudaD_apply_pow_abs(dim3 Gr, dim3 Bl, double* mat, double power, bool include_sign, MatrixDim d);
void cudaD_apply_heaviside(dim3 Gr, dim3 Bl, double* mat, MatrixDim d);
void cudaD_apply_floor(dim3 Gr, dim3 Bl, double* mat, double floor_val, MatrixDim d);
void cudaD_copy_cols(dim3 Gr, dim3 Bl, double* dst, const double* src, const MatrixIndexT_cuda* reorder, MatrixDim dst_dim, int src_stride);
void cudaD_add_cols(dim3 Gr, dim3 Bl, double* dst, const double* src, const MatrixIndexT_cuda* reorder, MatrixDim dst_dim, int src_stride);
void cudaD_copy_rows(dim3 Gr, dim3 Bl, double* dst, const double* src, const MatrixIndexT_cuda* reorder, MatrixDim dst_dim, int src_stride);
void cudaD_copy_rows_direct(dim3 Gr, dim3 Bl, double* dst, const double* const* src, MatrixDim dst_dim);
void cudaD_copy_to_rows_direct(dim3 Gr, dim3 Bl, double* const* dst, const double* src, MatrixDim src_dim);
void cudaD_add_rows(dim3 Gr, dim3 Bl, double alpha, double* dst, const double* src, const MatrixIndexT_cuda* reorder, MatrixDim dst_dim, int src_stride);
void cudaD_add_rows_direct(dim3 Gr, dim3 Bl, double alpha, double* dst, const double* const* src, MatrixDim dst_dim);
void cudaD_add_to_rows_direct(dim3 Gr, dim3 Bl, double alpha, double* const* dst, const double* src, MatrixDim src_dim);
void cudaD_apply_ceiling(dim3 Gr, dim3 Bl, double* mat, double ceiling_val, MatrixDim d);
void cudaD_set_diag(int Gr, int Bl, double* mat, double value, MatrixDim d);
void cudaD_set_diag_packed(int Gr, int Bl, double* mat, double value, int dim);
void cudaD_add_diag_packed(int Gr, int Bl, double* mat, double value, int dim);
void cudaD_set_const(dim3 Gr, dim3 Bl, double *mat, double value, MatrixDim d);
void cudaD_set_zero_above_diag(dim3 Gr, dim3 Bl, double* mat, MatrixDim d);
void cudaD_add(dim3 Gr, dim3 Bl, double *mat, double value, MatrixDim d);
void cudaD_add_vec2(dim3 Gr, dim3 Bl, double *mat, const double *vec, const double alpha, int dim);
void cudaD_scale_diag_packed(int Gr, int Bl, double* mat, double value, int dim);
void cudaD_scale(dim3 Gr, dim3 Bl, double *mat, double value, MatrixDim d);
void cudaD_apply_log(dim3 Gr, dim3 Bl, double *mat, MatrixDim d);
void cudaD_mul_elements(dim3 Gr, dim3 Bl, double *mat, const double *A, MatrixDim dst_d, int src_stride);
void cudaD_div_elements(dim3 Gr, dim3 Bl, double *mat, const double *A, MatrixDim dst_d, int src_stride);
void cudaD_max(dim3 Gr, dim3 Bl, double *mat, const double *A, MatrixDim dst_d, int src_stride);
void cudaD_mul_cols_vec(dim3 Gr, dim3 Bl, double *mat, const double *scale, MatrixDim d);
void cudaD_mul_rows_vec(dim3 Gr, dim3 Bl, double *mat, const double *scale, MatrixDim d);
void cudaD_mul_rows_group_mat(dim3 Gr, dim3 Bl, double *y, const double *x, MatrixDim d, int src_stride, int group_size);
void cudaD_calc_pnorm_deriv(dim3 Gr, dim3 Bl, double *y, const double *x1, const double *x2,  MatrixDim d, int src_stride, int group_size, double power);
void cudaD_diff_group_pnorm(dim3 Gr, dim3 Bl, double *id, const double *iv,
                            const double *ov, const double* od,
                            MatrixDim id_dim, int iv_stride, int ov_stride,
                            int od_stride, int group_size, double power);
void cudaD_calc_group_max_deriv(dim3 Gr, dim3 Bl, double *y, const double *x1, const double *x2,  MatrixDim d, int src_stride, int group_size);
void cudaD_div_rows_vec(dim3 Gr, dim3 Bl, double *mat, const double *vec_div, MatrixDim d);
void cudaD_add_mat(dim3 Gr, dim3 Bl, double alpha, const double *src, double *dst, MatrixDim d, int src_stride, int A_trans);
void cudaD_add_mat_blocks(dim3 Gr, dim3 Bl, double alpha, const double *src, int32_cuda num_row_blocks, int32_cuda num_col_blocks, double *dst, MatrixDim d, int src_stride, int A_trans);
void cudaD_add_mat_mat_div_mat(dim3 Gr, dim3 Bl, const double *A, const double *B, const double *C, double *dst, MatrixDim d, int stride_a, int stride_b, int stride_c);
void cudaD_add_vec_to_cols(dim3 Gr, dim3 Bl, double alpha, const double *col, double beta, double *dst, MatrixDim d);
void cudaD_add_vec_to_rows(dim3 Gr, dim3 Bl, double alpha, const double *row, double beta, double *dst, MatrixDim d);
void cudaD_add_mat_diag_vec(dim3 Gr, dim3 Bl, double alpha, double *mat, MatrixDim mat_dim, const double *mat2, int mat2_row_stride, int mat2_col_stride, const double *vec, double beta);
void cudaD_add_mat_mat_elements(dim3 Gr, dim3 Bl, double *data, const double *srcA_data, const double *srcB_data, MatrixDim dim, int srcA_stride, int srcB_stride, double alpha, double beta);

/*
 * CuVector
 */
void cudaD_max_mat_cols(int Gr, int Bl, double* result, const double* mat, const MatrixDim d);
void cudaD_min_mat_cols(int Gr, int Bl, double* result, const double* mat, const MatrixDim d);
void cudaD_sum_mat_cols(int Gr, int Bl, double* result, const double* mat, const MatrixDim d);
void cudaD_replace_value(int Gr, int Bl, double *v, int dim, double orig, double changed);
void cudaD_set_bias_params(int Gr, int Bl, double* v, const double* a, double param_1, double param_2, double param_3, int* flag, int dim);
void cudaD_vec_mul_elements(int Gr, int Bl, double* v, const double* a, int dim);
void cudaD_vec_soft_max(int Gr, int Bl, double* v, int dim);
void cudaD_vec_min(int Gr, int Bl, const double* v, double* value, int dim, int inc);
void cudaD_vec_max(int Gr, int Bl, const double* v, double* value, int dim, int inc);
void cudaD_trace_mat_mat_trans(dim3 Gr, dim3 Bl, const double* A, const double* B, MatrixDim dA, int B_stride, double* value);
void cudaD_trace_mat_mat(dim3 Gr, dim3 Bl, const double* A, const double* B, MatrixDim dA, int B_stride, double* value);
void cudaD_add_diag_mat_mat_MNT(int Gr, int Bl, const double alpha,
                                const double* M, const MatrixDim dim_M,
                                const double* N, const int stride_N,
                                const double beta, double* v);
void cudaD_add_diag_mat_mat_MTN(dim3 Gr, dim3 Bl, const double alpha,
                                const double* M, const int strid_M,
                                const double* N, const MatrixDim dim_N,
                                const double beta, double* v);
void cudaD_add_diag_mat_mat_MN(dim3 Gr, dim3 Bl, const double alpha,
                               const double* M, const int strid_M,
                               const double* N, const MatrixDim dim_N,
                               const double beta, double* v);
void cudaD_add_vec_vec(int Gr, int Bl, double alpha, double* v, const double* x, const double* y, double beta, int dim);
void cudaD_copy_col_from_mat_df(int Gr, int Bl, double* v, int col, const double* mat, MatrixDim dmat, int dim);
void cudaD_copy_col_from_mat_fd(int Gr, int Bl, float* v, int col, const double* mat, MatrixDim dmat, int dim);
void cudaD_vec_sum(int Gr, int Bl, double* v, double* value, int dim, int inc);
void cudaD_vec_copy_diag_from_packed(int Gr, int Bl, double *dst, const double *src, int dim);
void cudaD_vec_apply_floor(int Gr, int Bl, double* v, double floor_val, float* num, int dim);
void cudaD_vec_apply_ceiling(int Gr, int Bl, double* v, double ceiling_val, float* num, int dim);
void cudaD_vec_apply_exp(int Gr, int Bl, double* v, int dim);
void cudaD_vec_apply_log(int Gr, int Bl, double* v, double* flag, int dim);
void cudaD_trace(int Gr, int Bl, double* mat, double* value, int dim);
void cudaD_invert_elements(dim3 Gr, dim3 Bl, double *data, MatrixDim d);
// note: B_trans is nonzero if B is tranposed.
void cudaD_add_mat_blockmat(dim3 Gr, dim3 Bl, double *data, MatrixDim d, const double *Adata,
                            int A_num_rows, int A_num_cols, int A_row_stride, int A_col_stride,
                            const CuBlockMatrixData *B_cu_data, int B_num_blocks,
                            double alpha, double beta, int B_trans);
void cudaD_block_add_mat_mat(dim3 Gr, dim3 Bl, CuBlockMatrixData *B_cu_data, int num_blocks,
                             const double *C_data, int C_num_cols, int C_row_stride, int C_col_stride,
                             const double *D_data, int D_row_stride, int D_col_stride,
                             double alpha, double beta);


/*
 * cu::
 */
void cudaD_softmax_reduce(size_t Gr, size_t Bl, double *y, const double *x, MatrixDim d, int src_stride);
void cudaD_log_softmax_reduce(size_t Gr, size_t Bl, double *y, const double *x, MatrixDim d, int src_stride);
void cudaD_soft_hinge(dim3 Gr, dim3 Bl, double *y, const double *x, MatrixDim d, int src_stride);
void cudaD_group_pnorm(dim3 Gr, dim3 Bl, double *y, const double *x, MatrixDim d, int src_stride, int group_size, double power);
void cudaD_group_spec_pnorm(dim3 Gr, dim3 Bl, double *y, const double *x,
                            MatrixDim d, int src_stride, int group_size,
                            double power);
void cudaD_group_max(dim3 Gr, dim3 Bl, double *y, const double *x, MatrixDim d, int src_stride, int group_size);
void cudaD_sigmoid(dim3 Gr, dim3 Bl, double *y, const double *x, MatrixDim d, int src_stride);
void cudaD_heaviside(dim3 Gr, dim3 Bl, double *y, const double *x, MatrixDim d, int src_stride);
void cudaD_diff_sigmoid(dim3 Gr, dim3 Bl, double *eout, const double *e, const double *y, MatrixDim d, int e_stride, int y_stride);
void cudaD_tanh(dim3 Gr, dim3 Bl, double *y, const double *x, MatrixDim d, int src_stride);
void cudaD_diff_tanh(dim3 Gr, dim3 Bl, double *eout, const double *e, const double *y, MatrixDim d, int e_stride, int y_stride);

void cudaD_regularize_l1(dim3 Gr, dim3 Bl, double *wei, double *grad, double l1, double lr, MatrixDim d, int stride_grad);
void cudaD_find_row_max_id(dim3 Gr, dim3 Bl, const double *mat, double *vec_val, int32_cuda *vec_id, MatrixDim d);
void cudaD_diff_xent(dim3 Gr, dim3 Bl, const int32_cuda *vec_tgt, double *mat_net_out, double *vec_log_post, MatrixDim d);
void cudaD_diff_softmax(dim3 Gr, dim3 Bl, double* x, const MatrixDim dim,
                        const double* value, const int value_stride,
                        const double* diff, const int diff_stride);
void cudaD_copy_rows_from_vec(dim3 Gr, dim3 Bl, double *mat_out, MatrixDim d_out, const double *v_in);

void cudaD_randomize(dim3 Gr, dim3 Bl, double *y, const double *x, const int32_cuda *copy_from, MatrixDim d_out, MatrixDim d_in);
void cudaD_splice(dim3 Gr, dim3 Bl, double *y, const double *x, const int32_cuda *off, MatrixDim d_out, MatrixDim d_in);
void cudaD_one(int Gr, int Bl, double* x, int dim);
void cudaD_copy(dim3 Gr, dim3 Bl, double *y, const double *x, const int32_cuda *copy_from, MatrixDim d_out, MatrixDim d_in);
void cudaD_copy_from_sp(dim3 Gr, dim3 Bl, const double* x, double* y, MatrixDim d_out);
void cudaD_take_lower(dim3 Gr, dim3 Bl, const double* x, double* y, MatrixDim d_in);
void cudaD_take_upper(dim3 Gr, dim3 Bl, const double* x, double* y, MatrixDim d_in);
void cudaD_take_mean(dim3 Gr, dim3 Bl, const double* x, double* y, MatrixDim d_in);


// some mostly mixed-type kernels.
void cuda_copy_from_mat_df(dim3 Gr, dim3 Bl, double* mat_out, const float* mat_in, MatrixDim d_out, MatrixDim d_in);
void cuda_copy_from_mat_ff(dim3 Gr, dim3 Bl, float* mat_out, const float* mat_in, MatrixDim d_out, MatrixDim d_in);
void cuda_copy_from_mat_fd(dim3 Gr, dim3 Bl, float *mat_out, const double* mat_in, MatrixDim d_out, MatrixDim d_in);
void cuda_copy_from_mat_dd(dim3 Gr, dim3 Bl, double *mat_out, const double* mat_in, MatrixDim d_out, MatrixDim d_in);
void cuda_copy_from_mat_df_trans(dim3 Gr, dim3 Bl, double* mat_out, const float* mat_in, MatrixDim d_out, MatrixDim d_in);
void cuda_copy_from_mat_ff_trans(dim3 Gr, dim3 Bl, float* mat_out, const float* mat_in, MatrixDim d_out, MatrixDim d_in);
void cuda_copy_from_mat_fd_trans(dim3 Gr, dim3 Bl, float *mat_out, const double* mat_in, MatrixDim d_out, MatrixDim d_in);
void cuda_copy_from_mat_dd_trans(dim3 Gr, dim3 Bl, double *mat_out, const double* mat_in, MatrixDim d_out, MatrixDim d_in);

void cuda_copy_from_smat_ff(dim3 Gr, dim3 Bl, float* mat_out, const MatrixElement<float>* smat_in, MatrixDim d_out, MatrixIndexT_cuda d_in);
void cuda_copy_from_smat_fd(dim3 Gr, dim3 Bl, float* mat_out, const MatrixElement<double>* smat_in, MatrixDim d_out, MatrixIndexT_cuda d_in);
void cuda_copy_from_smat_df(dim3 Gr, dim3 Bl, double* mat_out, const MatrixElement<float>* smat_in, MatrixDim d_out, MatrixIndexT_cuda d_in);
void cuda_copy_from_smat_dd(dim3 Gr, dim3 Bl, double* mat_out, const MatrixElement<double>* smat_in, MatrixDim d_out, MatrixIndexT_cuda d_in);
void cuda_copy_from_smat_ff_trans(dim3 Gr, dim3 Bl, float* mat_out, const MatrixElement<float>* smat_in, MatrixDim d_out, MatrixIndexT_cuda d_in);
void cuda_copy_from_smat_fd_trans(dim3 Gr, dim3 Bl, float* mat_out, const MatrixElement<double>* smat_in, MatrixDim d_out, MatrixIndexT_cuda d_in);
void cuda_copy_from_smat_df_trans(dim3 Gr, dim3 Bl, double* mat_out, const MatrixElement<float>* smat_in, MatrixDim d_out, MatrixIndexT_cuda d_in);
void cuda_copy_from_smat_dd_trans(dim3 Gr, dim3 Bl, double* mat_out, const MatrixElement<double>* smat_in, MatrixDim d_out, MatrixIndexT_cuda d_in);

void cudaF_trace_mat_smat(dim3 Gr, dim3 Bl, const float* mat_in, const MatrixElement<float>* smat_in, MatrixDim mat_d_in, MatrixIndexT_cuda smat_d_in, float* trace_vec_out);
void cudaF_trace_mat_smat_trans(dim3 Gr, dim3 Bl, const float* mat_in, const MatrixElement<float>* smat_in, MatrixDim mat_d_in, MatrixIndexT_cuda smat_d_in, float* trace_vec_out);
void cudaD_trace_mat_smat(dim3 Gr, dim3 Bl, const double* mat_in, const MatrixElement<double>* smat_in, MatrixDim mat_d_in, MatrixIndexT_cuda smat_d_in, double* trace_vec_out);
void cudaD_trace_mat_smat_trans(dim3 Gr, dim3 Bl, const double* mat_in, const MatrixElement<double>* smat_in, MatrixDim mat_d_in, MatrixIndexT_cuda smat_d_in, double* trace_vec_out);

void cudaD_matrix_add_elements(dim3 Gr, dim3 Bl, double *data, MatrixDim dim, double alpha, MatrixElement<double>* x, int num_elements);
void cudaD_matrix_add_indexed_values(dim3 Gr, dim3 Bl, MatrixDim dim, double alpha, const Int32Pair* indices, const double* x, int s, double* data);
void cudaD_comp_obj_deriv(dim3 Gr,dim3 Bl, MatrixElement<double>* x, int s, const double* z, MatrixDim d, double* z2, MatrixDim d2, double* t);

void cudaD_sy_add_tr2(dim3 Gr, dim3 Bl, double alpha, double beta, const double* T, MatrixDim tdim,
                      double *S, MatrixDim sdim);
void cudaD_sum_column_ranges(dim3 Gr, dim3 Bl, double *data, MatrixDim dim,
                             const double *src_data, MatrixDim src_dim,
                             const Int32Pair *indices);
void cudaD_add_row_ranges(dim3 Gr, dim3 Bl, double *data, MatrixDim dim,
                          const double *src_data, MatrixDim src_dim,
                          const Int32Pair *indexes);
void cudaD_matrix_lookup(dim3 Gr, dim3 Bl, const double *data, MatrixDim dim,
                         const Int32Pair *indices, int indices_size,
                         double *output);

void cudaD_equal_element_mask(dim3 Gr, dim3 Bl, const double *mat1,
                              const double *mat2, double *mask, MatrixDim mat1_dim,
                              int mat2_stride, int mask_stride);



} // extern "C"

#endif // HAVE_CUDA


#endif

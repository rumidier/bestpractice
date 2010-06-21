#define X_SIZE 60
#define Y_SIZE 30

int
matrix [X_SIZE][Y_SIZE];

void
init_matrix (void)
{
  regist int *matrix_ptr;

  for (matrix_ptr = &matrix[0][0];
       matrix_ptr <= &matrix[X_SIZE - 1] [Y_SIZE - 1];
       ++matrix_ptr) {
    *matrix_ptr = -1;
  }
}

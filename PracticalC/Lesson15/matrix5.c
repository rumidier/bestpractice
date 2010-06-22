#define X_SIZE 60
#define Y_SIZE 30

int
matrix [X_SIZE] [Y_SIZE];

void
init_matrix (void)
{
  register int index;
  register int *matrix_ptr;

  matrix_ptr = &matrix [0][0];

  for (index = 0; index < X_SIZE * Y_SIZE; ++index) {
    *matrix_ptr = -1;
    ++matrix_ptr;
  }
}

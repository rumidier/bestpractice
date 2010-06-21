extern float lookup (int index);

float point_color (int point_number)
{
  float correction;
  extern float red, green, blue;

  correction = lookup (point_number);

  return (red * correction * 100.0 +
          blue * correction * 10.0 +
          green * correction);
}

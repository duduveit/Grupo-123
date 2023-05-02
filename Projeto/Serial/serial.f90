program calcular_e

  integer :: n = 20, i
  real(kind = 16) :: e = 1.0

  do i = 1, n
    e = e + 1.0 / fat(i)
  end do

  print *, "O valor de e eh = ", e

contains

  function fat(n) result(resultado)
    integer :: n
    real :: resultado
    integer :: i

    resultado = 1.0
    do i = 2, n
      resultado = resultado * i
    end do

  end function fat

end program calcular_e

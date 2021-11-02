A = [
    16, 18, 5, 19, 19;
    18, 12, 10, 3, 9;
    2, 1, 19, 19, 16
    ]

[Q, R] = qr(A)
A
RES = Q * R

[Q, R, P] = qr(A)
RES1 = A * P
RES2 = Q * R

A = [2, 19, 18, 7, 0; 8, 13, 13, 13, 5;
    18, 0, 15, 3, 0; 15, 16, 14, 14, 1];

[U, S, V] = svd(A);
RES=U*U';
RES=V*V';

RES=U*S*V';

s = diag(S)
rank_A = nnz(s)

column_basis = U(:,logical(s))

null_basis = V(:,~s)
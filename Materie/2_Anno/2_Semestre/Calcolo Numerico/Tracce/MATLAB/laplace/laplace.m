function d=laplace(A)
% Sviluppo di Lapace lungo la prima riga per il calcolo
% del determinante di una matrice quadrata
% A: matrice quadrata
% d: determinante di A

[m,n]=size(A);
if m~=n 
    error('matrice non quadrata')
end


if n==1
    d=A;
else
    d=0;
    for j=1:n
        A1j=A(2:m,[1:j-1,j+1:n]);
        d=d+(-1)^(1+j)*A(1,j)*laplace(A1j);
    end
end
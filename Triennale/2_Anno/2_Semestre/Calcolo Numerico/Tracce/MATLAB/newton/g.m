function y=g(x,ord)
if nargin==1
    ord=0;
end

switch ord
    case 0
        y=x-exp(-x);
    case 1
        y=1+exp(-x);
    otherwise
        error('ordine di derivazione non definito')
end
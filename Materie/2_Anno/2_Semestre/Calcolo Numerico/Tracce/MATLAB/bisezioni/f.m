function y=f(x,ord)

if nargin==1
    ord=0;
end

if ord==0
    y=x-cos(x);
elseif ord==1
    y=1+sin(x);
else
    error('ordine di derivazione non definito')
end
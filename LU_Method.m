clc;
clear;

A = input('Please Enter coefficient Matrix A: ');

% Assuming A is square
N = size(A, 1);

% Generate a random vector b
b = rand(N, 1);

L = zeros(N, N);
U = zeros(N, N);

% LU decomposition algorithm
for k = 1:N
    % U matrix
    for j = k:N
        sum = 0;
        for p = 1:k-1
            sum = sum + L(k, p) * U(p, j);
        end
        U(k, j) = A(k, j) - sum;
    end
    
    % L matrix
    for i = k+1:N
        sum = 0;
        for p = 1:k-1
            sum = sum + L(i, p) * U(p, k);
        end
        L(i, k) = (A(i, k) - sum) / U(k, k);
    end
    
    L(k, k) = 1; % Set diagonal element of L to 1
end

% Display L and U matrices
disp('L matrix:');
disp(L);
disp('U matrix:');
disp(U);

% Solve Ly = b for y
y = zeros(N, 1);
for i = 1:N
    sum = 0;
    for j = 1:i-1
        sum = sum + L(i, j) * y(j);
    end
    y(i) = (b(i) - sum) / L(i, i);
end

% Solve Ux = y for x
x = zeros(N, 1);
for i = N:-1:1
    sum = 0;
    for j = i+1:N
        sum = sum + U(i, j) * x(j);
    end
    x(i) = (y(i) - sum) / U(i, i);
end

% Display the solution vector x
disp('Solution vector x:');
disp(x);

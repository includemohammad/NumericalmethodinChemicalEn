clc;
clear all;
close all;

% Define the dimensions of the matrix
n = 204;

% Generate a random coefficient matrix A and constant vector b
A = rand(n, n); % A random 204x204 matrix
b = rand(n, 1); % A random 204x1 vector

% Convert A to a diagonally dominant matrix
for i = 1:n
    A(i, i) = sum(abs(A(i, :))) + 1; % Adjust the diagonal element
end

% Gaussian elimination without using a function
% Elimination phase
for k = 1:n-1
    for i = k+1:n
        if A(i,k) ~= 0
            c = A(i,k) / A(k,k);
            A(i,k+1:n) = A(i,k+1:n) - c * A(k,k+1:n);
            b(i) = b(i) - c * b(k);
        end
    end
end

% Solution phase: Back substitution
x = zeros(n, 1);
for k = n:-1:1
    x(k) = (b(k) - A(k,k+1:n)*x(k+1:n)) / A(k,k);
end

% Display the final solution
disp('Solution x:');
disp(x);

% Write the solution to a txt file
fileID = fopen('solution.txt', 'w');
fprintf(fileID, '%f\n', x);
fclose(fileID);

disp('Solution written to solution.txt');

clc;
clear all;
close all;

%% Solving a Linear System using the Gauss-Seidel Method
% This example demonstrates how to solve a 204x204 linear system using the
% Gauss-Seidel method. First, we define the coefficient matrix and the constant
% vector, and then we use the Gauss-Seidel method to find the solution.

%% Define the coefficient matrix A and the constant vector b
% In this section, we define the matrix A and the vector b.

n = 204; % Matrix dimension
A = rand(n, n); % Random 204x204 matrix
b = rand(n, 1); % Random 204x1 vector

% Convert A to a diagonally dominant matrix
for i = 1:n
    A(i, i) = sum(abs(A(i, :))) + 1; % Adjust diagonal element
end

%% Display matrix A and vector b
% In this section, we display the matrix A and the vector b.

disp('Matrix A:');
disp(A);
disp('Vector b:');
disp(b);

%% Set parameters for the Gauss-Seidel method
% In this section, we set the tolerance and the maximum number of iterations.

tol = 1e-5; % Tolerance
max_iter = 1000; % Maximum number of iterations

%% Initialize the solution vector x
% In this section, we initialize the vector x.

x = zeros(n, 1); % Initial vector

%% Execute the Gauss-Seidel method
% In this section, we execute the Gauss-Seidel method.

for k = 1:max_iter
    x_old = x;
    for i = 1:n
        sum = b(i);
        for j = 1:n
            if j ~= i
                sum = sum - A(i,j) * x(j);
            end
        end
        x(i) = sum / A(i,i);
    end
    if norm(x - x_old, inf) < tol
        break;
    end
end

%% Display the final result
% In this section, we display the final result.

disp('Solution x:');
disp(x);

%% Save output to a text file
% Open a file for writing
fileID = fopen('solution_output.txt', 'w');

% Write matrix A to file
fprintf(fileID, 'Matrix A:\n');
for i = 1:n
    fprintf(fileID, '%f ', A(i, :));
    fprintf(fileID, '\n');
end

% Write vector b to file
fprintf(fileID, '\nVector b:\n');
fprintf(fileID, '%f\n', b);

% Write solution vector x to file
fprintf(fileID, '\nSolution vector x:\n');
fprintf(fileID, '%f\n', x);

% Close the file
fclose(fileID);

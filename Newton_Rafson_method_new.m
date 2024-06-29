% Define the size of the matrix
n = 204;

% Generate a random sparse matrix A of size 204x204
% Ensure it's diagonally dominant for convergence
A = sprandsym(n, 0.05, 1, 1); 
A = A + n * speye(n);

% Generate a random vector b of size 204
b = rand(n, 1);

% Initial guess
x0 = zeros(n, 1);

% Tolerance and maximum number of iterations
tol = 1e-6;
max_iter = 100;

% Newton-Raphson Method
x = x0;
for k = 1:max_iter
    Fx = A * x - b;
    JFx = A; % Because the matrix is fixed
    delta = -JFx \ Fx;
    x = x + delta;
    if norm(delta, inf) < tol
        break;
    end
end

% Save the result to a text file
fileID = fopen('output.txt', 'w');
fprintf(fileID, 'Solution:\n');
for i = 1:n
    fprintf(fileID, '%f\n', x(i));
end
fclose(fileID);

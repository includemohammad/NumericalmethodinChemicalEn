function x = GaussSeidel(A, b, rho)
% Solves Ax = b by Gauss-Seidel iterative method
% A: coefficient matrix (should be square and diagonally dominant)
% b: constant vector
% rho: relaxation factor (optional, default is 1)

if nargin < 3
    rho = 1; % Default relaxation factor
end

% Initialization
itmax = 500; 
tol = 1e-8;
b = (b(:).')'; % Ensure b is a column vector
n = length(b); 
[nr, nc] = size(A);

% Check for consistency
if nr ~= nc
    error('Matrix A is not square.');
end
if nr ~= n
    error('Matrix A and vector b are not consistent.');
end
if det(A) == 0
    fprintf('\n Rank = %7.3g\n', rank(A));
    error('A is singular.');
end

% Initial values
x = zeros(n, 1); % Initial guess for the solution vector
M = A;
for k = 1:n
    M(k, k) = 0; % Set diagonal elements of M to 0
end

% Check diagonal dominancy of A
for k = 1:n
    if sum(abs(M(k, :))) > abs(A(k, k))
        disp('A is not diagonally dominant.');
        return;
    end
end

% Normalize M and s
s = zeros(n, 1); % Initialization for s
for k = 1:n
    M(k, :) = M(k, :) / A(k, k);
    s(k) = b(k) / A(k, k);
end

% Iteration
iter = 0; 
while true
    x0 = x; % Store the current solution
    for k = 1:n
        x(k) = rho * (s(k) - M(k, :) * x) + (1 - rho) * x(k);
    end
    iter = iter + 1;
    % Check for convergence
    if max(abs(x - x0) ./ abs(x)) <= tol || iter >= itmax
        break;
    end
end

% Display results
fprintf('Number of iterations: %d\n', iter);
fprintf('Solution vector x:\n');
disp(x);

end

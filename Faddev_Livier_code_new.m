% Define the size of the matrix
n = 204;

% Generate a random integer matrix A of size 204x204
A = randi([-10, 10], n, n); % Random integers between -10 and 10

% Ensure A is diagonally dominant for better numerical stability
for i = 1:n
    A(i, i) = sum(abs(A(i, :))) + 1;
end

% Check if the input matrix A is square
if size(A, 1) ~= size(A, 2)
    error('Input matrix must be square');
end

% Initialize variables
S = eye(n);  % S_0 is the identity matrix
coeffs = zeros(1, n+1);  % Coefficients of the characteristic polynomial
coeffs(n+1) = 1;  % The leading coefficient is always 1 (for ?^n)

% Display header for debugging
disp('Step | Trace Value | Coefficient');

for k = 1:n
    % Compute the trace of A*S_(k-1)
    trace_val = trace(A * S);
    
    % Compute the k-th coefficient
    coeff = -trace_val / k;
    
    % Display values for debugging
    fprintf('%4d | %11.4f | %11.4f\n', k, trace_val, coeff);
    
    % Check for NaN or Inf in coefficient
    if isnan(coeff) || isinf(coeff)
        error('Encountered NaN or Inf in coefficients calculation at step %d with trace value %f', k, trace_val);
    end
    
    coeffs(n+1-k) = coeff;
    
    % Update S
    S = A * S + coeff * eye(n);
end

% Construct the characteristic polynomial as a symbolic expression
syms lambda;
char_poly = lambda^n;
for k = 1:n
    char_poly = char_poly + coeffs(n+1-k) * lambda^(n-k);
end

% Solve for the eigenvalues using the roots of the characteristic polynomial
eigenvalues = roots(coeffs);

% Save the eigenvalues to a text file
fileID = fopen('eigenvalues.txt', 'w');
fprintf(fileID, 'Eigenvalues:\n');
for i = 1:length(eigenvalues)
    fprintf(fileID, '%f\n', eigenvalues(i));
end
fclose(fileID);

disp('Eigenvalues have been saved to eigenvalues.txt');

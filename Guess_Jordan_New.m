% Define the size of the matrix
n = 204;

% Generate a random integer matrix A of size 204x204
A = randi([-10, 10], n, n); % Random integers between -10 and 10

% Ensure A is invertible by adding a diagonal matrix
A = A + n * eye(n);

% Augment A with the identity matrix of the same size
Aug = [A eye(n)];

% Apply Gauss-Jordan elimination
for i = 1:n
    % Partial pivoting
    [~, maxIndex] = max(abs(Aug(i:n, i)));
    maxIndex = maxIndex + i - 1;
    if i ~= maxIndex
        % Swap rows
        temp = Aug(i, :);
        Aug(i, :) = Aug(maxIndex, :);
        Aug(maxIndex, :) = temp;
    end
    
    % Make the diagonal contain all ones
    Aug(i, :) = Aug(i, :) / Aug(i, i);
    
    % Make all rows except the current one have zeros in the current column
    for j = 1:n
        if i ~= j
            Aug(j, :) = Aug(j, :) - Aug(j, i) * Aug(i, :);
        end
    end
end

% The right half of Aug is now the inverse of A
A_inv = Aug(:, n+1:end);

% Save the original matrix and its inverse to text files
dlmwrite('matrix_A.txt', A, 'delimiter', '\t', 'precision', 6);
dlmwrite('inverse_A.txt', A_inv, 'delimiter', '\t', 'precision', 6);

disp('Original matrix A and its inverse have been saved to matrix_A.txt and inverse_A.txt');

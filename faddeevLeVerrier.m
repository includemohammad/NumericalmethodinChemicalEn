function [coeffs, char_poly] = faddeevLeVerrier(A)
    % Check if the input matrix A is square
    [n, m] = size(A);
    if n ~= m
        error('Input matrix must be square');
    end
    
    % Initialize variables
    S = eye(n);  % S_0 is the identity matrix
    coeffs = zeros(1, n+1);  % Coefficients of the characteristic polynomial
    coeffs(n+1) = 1;  % The leading coefficient is always 1 (for ?^n)

    for k = 1:n
        % Compute the trace of A*S_(k-1)
        trace_val = trace(A * S);
        
        % Compute the k-th coefficient
        coeffs(n+1-k) = -trace_val / k;
        
        % Update S
        S = A * S + coeffs(n+1-k) * eye(n);
    end
    
    % Construct the characteristic polynomial as a symbolic expression
    syms lambda;
    char_poly = lambda^n;
    for k = 1:n
        char_poly = char_poly + coeffs(n+1-k) * lambda^(n-k);
    end
end




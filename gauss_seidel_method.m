function x = gauss_seidel_method(A, b, tol, max_iter)
    n = length(b);
    x = zeros(n, 1);
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
end

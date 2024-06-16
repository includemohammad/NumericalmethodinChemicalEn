function x = newton_raphson_method(A, b, x0, tol, max_iter)
    x = x0;
    for k = 1:max_iter
        Fx = A * x - b;
        JFx = A; %Because the matrix is ??fixed
        delta = -JFx \ Fx;
        x = x + delta;
        if norm(delta, inf) < tol
            break;
        end
    end
end

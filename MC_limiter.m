function [x] = MC_limiter(a,b,dx,max_t,dt)
        %initial conditions
        function [q_0] = q_0(x)
            if x <= 1
                q_0 = 1;
            else
                q_0 = 0;
            end
        end
        %initialize space, time, nu
        space = a:dx:b; 
        time = 0:dt:max_t;
        nu = dt/dx;
        %initialize Q
        Q=zeros(1,length(space));
        for j=1:length(space)
           Q(j) = q_0(space(j));
        end
        %initialize flux
        F=zeros(1,length(Q)+1);
        F(1) = 1;
        if Q(2)-Q(1) == 0
            F(2) = Q(1);
        else
            theta_0 = (Q(1) - 1)/(Q(2)-Q(1));
            phi_0 = max(0,min(1.5+theta_0/2,2,2*theta_0));
            F(2) = Q(1) + phi_0*0.5*(1-nu)*(Q(2)-Q(1));
        end
        for i=3:length(Q)
            if Q(i)-Q(i-1) == 0
               F(i) = Q(i-1);
            else
                theta = (Q(i-1)-Q(i-2))/(Q(i)-Q(i-1));
                phi = max(0,min([0.5+theta/2,2,2*theta]));
                F(i) = Q(i-1) + phi*0.5*(1-nu)*(Q(i)-Q(i-1));
            end
        end
        F(length(Q)+1) = Q(length(Q)); %upwind flux for rightmost edge
        %step through time
        for j=2:length(time)
            Q(1) = 1;
            for k=2:length(Q)
               Q(k) = Q(k) + (dt/dx)*(F(k)-F(k+1));
            end
            
            if Q(2)-Q(1) == 0
                F(2) = Q(1);
            else
                theta_0 = (Q(1) - 1)/(Q(2)-Q(1));
                phi_0 = max(0,min([0.5+theta_0/2,2,2*theta_0]));
                F(2) = Q(1) + phi_0*0.5*(1-nu)*(Q(2)-Q(1));
            end
            
            for i=3:length(Q)
                theta = (Q(i-1)-Q(i-2))/(Q(i)-Q(i-1));
                phi = max(0,min([0.5+theta/2,2,2*theta]));
                F(i) = Q(i-1) + phi*0.5*(1-nu)*(Q(i)-Q(i-1));
            end
            F(length(Q)+1) = Q(length(Q));
        end
    end
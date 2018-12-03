function [] = lax_wendroff(a,b,dx,max_t,dt)
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
        for i=2:length(Q)
                F(i) = Q(i-1) + 0.5*(1-nu)*(Q(i)-Q(i-1));
        end
        F(length(Q)+1) = Q(length(Q)); %upwind flux at rightmost edge
        %step through time
        for j=2:length(time)
            Q(1) = 1;
            for k=2:length(Q)
               Q(k) = Q(k) + (dt/dx)*(F(k)-F(k+1));
            end
            for i=2:length(Q)
                F(i) = Q(i-1) + 0.5*(1-nu)*(Q(i)-Q(i-1));
                F(length(Q)+1) = Q(length(Q));
            end
        end
    end
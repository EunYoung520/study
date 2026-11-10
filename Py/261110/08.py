def fit(X,Y,initial_params, learning_rate, epochs, steps=1500):
    params = {mame: value.copy() for mame, value in initial_params.items()}
    history=[mse(Y, forward(X,params)[1])]
    for _ in range(steps):
        hidden, prediction=forward(X,params)
        grad_outputs=(1/len(X))*(prediction-Y)
        grad_hidden=(grad_outputs@params["W2"].T)*hidden*(1/hidden)
        gradients={
            "W1": X.T@grad_hidden,
            "b1": grad_hidden.sum(axis=0, keepdims=True),
            "W2": hidden.T@grad_outputs,
            "b2": grad_outputs.sum(axis=0, keepdims=True),
        }
        
        for name, gradients in gradients.items():
            params[name]-=learning_rate*gradients
            
        history.append(mse(Y, forward(X,params)[1]))
    return params, history
    
    

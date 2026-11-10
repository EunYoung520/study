rng=np.random.default_rng(42)

initial={"W1":rng.normal(0,0.05,(3,4)),
         "b1": np.zeros((1,4)),
         "W2":rng.normal(0,0.05,(4,1)),
         "b2": np.zeros((1,1))}

def forward(X,params):
    z=X@params["W1"]+params["b1"]
    hidden=1/(1+np.exp(-np.clip(z,-60,60)))
    prediction=hidden@params["W2"]+params["b2"]
    return hidden, prediction

def mse(actual, predicted):
    return np.mean(np.square(actual - predicted)**2)

_, before=forward(X_train,initial)

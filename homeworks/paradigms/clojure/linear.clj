(defn v+ [a, b] (mapv + a b))
(defn v- [a, b] (mapv - a b))
(defn v* [a, b] (mapv * a b))
(defn scalar [a, b] (apply + (v* a b)))
(defn vect [a, b] (let [[a1 a2 a3] a [b1 b2 b3] b]
                    [(- (* a2 b3) (* a3 b2)), (- (* a3 b1) (* a1 b3)), (- (* a1 b2) (* a2 b1))]))
(defn v*s [a, b] (mapv (fn [n] (* b n)) a))

(defn m+ [a, b] (mapv v+ a b))
(defn m- [a, b] (mapv v- a b))
(defn m* [a, b] (mapv v* a b))
(defn m*s [a, b] (mapv (fn [n] (v*s n b)) a))
(defn m*v [a, b] (mapv (fn [n] (scalar n b)) a))
(defn transpose [a] (apply mapv vector a))
(defn m*m [a, b] (mapv (fn [n] (mapv (fn [m] (scalar n m)) (transpose b))) a))

(transpose [[1 2 3] [4 5 6] [7 8 9]])
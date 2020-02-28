def distance(p:Vector[Double], q:Vector[Double]) : Double = {
	var dist =  math.sqrt(p.zip(q).map(pair => math.pow((pair._1 - pair._2),2)).reduce(_+_))
	return dist
}
 
def closestpoint(q: Vector[Double], candidates: Array[Vector[Double]]): Vector[Double] = {
	var bestIndex = 0
	var closest = Double.PositiveInfinity
	for (i <-0 until candidates.length) {
		val tempdist = distance(q,candidates(i))
		if(tempdist < closest){
			closest = tempdist
			bestIndex = i
		}
	}
	return candidates(bestIndex)
	
}
 
def add_vec(v1: Vector[Double], v2: Vector[Double]): Vector[Double] = {
	var newVector = v1.zip(v2).map(pair => (pair._1 + pair._2))
	return newVector
}
 
def average(cluster: Iterable[Vector[Double]]): Vector[Double] = {
	val numVectors = cluster.size
	var out = Vector(0.0,0.0)
	var it = cluster.toIterator
	while(it.hasNext){
		out = add_vec(out,it.next())
	}
	var res = out.map(x => (x/numVectors))
	return res
}

def distanceA(p:Array[Vector[Double]], q:Array[Vector[Double]]) : Double = {
	var dist = p.zip(q).map(pair => distance(pair._1,pair._2)).reduce(_+_);
	dist = dist/p.length
	return dist
}
////////////////////////
// Main Program Below //
////////////////////////

//Write something here.

var lines = sc.textFile("clustering_dataset.txt");
var data = lines.map(l => Vector.empty ++ l.split('\t').map(_.toDouble))

var k = 3

var centers = data.takeSample(false,k,99)
var centersBefore = centers

var minDist = 1e-6

var d = 1 + minDist

do {
	var closest = data.map(p => (closestpoint(p,centers),p))
	var pointgroup = closest.groupByKey()
	var newCenters = pointgroup.mapValues(ps => average(ps))
	var editedCenters = newCenters.values
	d = distanceA(centers,editedCenters.collect)
	centers = editedCenters.collect
	println("Distance = ")
	println(d)


}while (d >minDist)

println("Initial cluster centers")
centersBefore.foreach(println)
println("Centers after Kmeans cluster")
centers.foreach(println)

system.exit(0)

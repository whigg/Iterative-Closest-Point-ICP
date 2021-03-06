#ifndef ANNHELPER_H
#define ANNHELPER_H

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "ANN/ANN.h"

class ANNHelper {
public:
	ANNHelper ():dim(2), k(1), eps(0), n_pts(0){}
	ANNHelper (int dim, int k, double eps, int size){
		this->dim = dim;
		this->k = k;
		this->eps = eps;
		this->n_pts = size;
		query_pt = annAllocPt(dim);
		data_pts = annAllocPts(n_pts, dim);	// allocate data points
		nn_idx = new ANNidx[k];				// allocate near neigh indices
		dists = new ANNdist[k];				// allocate near neighbor dists
	}
	~ANNHelper (){}

	cv::Point2d findClosestPt(cv::Point2d pt);
	void initializeKdTree ();

	ANNpointArray		data_pts;				// data points
	ANNpoint			query_pt;				// query point
	ANNidxArray			nn_idx;					// near neighbor indices
	ANNdistArray		dists;					// near neighbor distances
	ANNkd_tree*			kd_tree;				// search structure
	int dim, k, n_pts;
	double eps;

private:

};

#endif
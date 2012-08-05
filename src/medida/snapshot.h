//
// Copyright (c) 2012 Daniel Lundin
//

#ifndef MEDIDA_METRICS_SNAPSHOT_H_
#define MEDIDA_METRICS_SNAPSHOT_H_

#include <cstddef>
#include <vector>

namespace medida {

class Snapshot {
public:
  Snapshot();
  Snapshot(std::vector<double> values);
  Snapshot(std::vector<long> values);
  ~Snapshot();
  std::size_t size() const;
  double getValue(double quantile) const;
  double getMedian() const;
  double get75thPercentile() const;
  double get95thPercentile() const;
  double get98thPercentile() const;
  double get99thPercentile() const;
  double get999thPercentile() const;
  std::vector<double> getValues() const;
  // void dump(File output); 
protected:
  std::vector<double> values_;
  static const double kMEDIAN_Q = 0.5;
  static const double kP75_Q = 0.75;
  static const double kP95_Q = 0.95;
  static const double kP98_Q = 0.98;
  static const double kP99_Q = 0.99;
  static const double kP999_Q = 0.999;
};

}

#endif // MEDIDA_METRICS_SNAPSHOT_H_

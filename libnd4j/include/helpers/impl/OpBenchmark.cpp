//
// Created by raver on 2/28/2019.
//

#include "../OpBenchmark.h"

namespace nd4j {
    OpBenchmark::OpBenchmark(std::string name, NDArray *x, NDArray *y, NDArray *z) {
        _testName = name;
        _x = x;
        _y = y;
        _z = z;
    }

    OpBenchmark::OpBenchmark(std::string name, NDArray *x, NDArray *z) {
        _testName = name;
        _x = x;
        _z = z;
    }

    OpBenchmark::OpBenchmark(std::string name, NDArray *x, NDArray *z, std::initializer_list<int> axis) {
        _testName = name;
        _x = x;
        _z = z;
        _axis = std::vector<int>(axis);

        if (_axis.size() > 1)
            std::sort(_axis.begin(), _axis.end());
    }

    OpBenchmark::OpBenchmark(std::string name, NDArray *x, NDArray *z, std::vector<int> axis) {
        _testName = name;
        _x = x;
        _z = z;
        _axis = axis;

        if (_axis.size() > 1)
            std::sort(_axis.begin(), _axis.end());
    }

    NDArray& OpBenchmark::x() {
        return *_x;
    }

    int OpBenchmark::opNum() {
        return _opNum;
    }
    std::string OpBenchmark::testName(){
        return _testName;
    }

    void OpBenchmark::setOpNum(int opNum) {
        _opNum = opNum;
    }

    void OpBenchmark::setTestName(std::string name){
        _testName = name;
    }

    void OpBenchmark::setX(NDArray *array) {
        _x = array;
    }

    void OpBenchmark::setY(NDArray *array) {
        _y = array;
    }

    void OpBenchmark::setZ(NDArray *array) {
        _z = array;
    }

    void OpBenchmark::setAxis(std::vector<int> axis) {
        _axis = axis;
    }

    void OpBenchmark::setAxis(std::initializer_list<int> axis) {
        _axis = axis;
    }
}
#!/bin/bash


echo "$(mkdir -p all_data )"
echo "$(mkdir -p all_data/timeConsumers)"
echo "$(mkdir -p all_data/timeProducers)"
echo "$(mkdir -p all_data/timeOnlyConsumers)"
echo "$(mkdir -p all_data/timeOnlyProducers)"
echo "$(mkdir -p finalTimes)"

for i in {1..1000000..10000}
do
	echo "$(./EPSX_1.out $i)"
	echo "$(cp timeConsumer.txt all_data/timeConsumers/timeConsumer_$i.txt)"
	echo "$(cp timeProducer.txt all_data/timeProducers/timeProducer_$i.txt)"
	echo "$(cp timeOnlyConsumer.txt all_data/timeOnlyConsumers/timeOnlyConsumer_$i.txt)"
	echo "$(cp timeOnlyProducer.txt all_data/timeOnlyProducers/timeOnlyProducer_$i.txt)"
done

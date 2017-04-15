#include <gtest/gtest.h>

#include <nnpack.h>
#include <nnpack/hwinfo.h>

#include <testers/convolution.h>

/*
 * Test that implementation works for a single tile of transformation
 */

TEST(FT8x8_BLOCK, DISABLED_single_tile) {
	ConvolutionTester()
		.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_block_based);
}

TEST(FT8x8_TUPLE, single_tile) {
	ConvolutionTester()
		.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_tuple_based);
}

TEST(FT16x16_BLOCK, DISABLED_single_tile) {
	ConvolutionTester()
		.inputSize(16, 16)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_block_based);
}

TEST(FT16x16_TUPLE, single_tile) {
	ConvolutionTester()
		.inputSize(16, 16)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_tuple_based);
}

TEST(WT8x8_BLOCK, DISABLED_single_tile) {
	ConvolutionTester()
		.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-3)
		.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_block_based);
}

TEST(WT8x8_TUPLE, single_tile) {
	ConvolutionTester()
		.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-3)
		.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_tuple_based);
}

/*
 * Test that the implementation handles extraction of input subtile
 */

TEST(FT8x8_BLOCK, DISABLED_input_subtile) {
	ConvolutionTester()
		.inputSize(4, 4)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_block_based);
}

TEST(FT8x8_TUPLE, input_subtile) {
	ConvolutionTester()
		.inputSize(4, 4)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_tuple_based);
}

TEST(FT16x16_BLOCK, DISABLED_input_subtile) {
	ConvolutionTester()
		.inputSize(4, 4)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_block_based);
}

TEST(FT16x16_TUPLE, input_subtile) {
	ConvolutionTester()
		.inputSize(4, 4)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_tuple_based);
}

TEST(WT8x8_BLOCK, DISABLED_input_subtile) {
	ConvolutionTester()
		.inputSize(4, 4)
		.iterations(100)
		.errorLimit(1.0e-4)
		.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_block_based);
}

TEST(WT8x8_TUPLE, input_subtile) {
	ConvolutionTester()
		.inputSize(4, 4)
		.iterations(100)
		.errorLimit(1.0e-4)
		.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_tuple_based);
}

/*
 * Test that the implementation handles multi-tile inputs
 */

TEST(FT8x8_BLOCK, DISABLED_multi_tile) {
	ConvolutionTester()
		.inputSize(13, 13)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_block_based);
}

TEST(FT8x8_TUPLE, multi_tile) {
	ConvolutionTester()
		.inputSize(13, 13)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_tuple_based);
}

TEST(FT16x16_BLOCK, DISABLED_multi_tile) {
	ConvolutionTester()
		.inputSize(29, 29)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_block_based);
}

TEST(FT16x16_TUPLE, multi_tile) {
	ConvolutionTester()
		.inputSize(29, 29)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_tuple_based);
}

TEST(WT8x8_BLOCK, DISABLED_multi_tile) {
	ConvolutionTester()
		.inputSize(13, 13)
		.iterations(100)
		.errorLimit(1.0e-3)
		.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_block_based);
}

TEST(WT8x8_TUPLE, multi_tile) {
	ConvolutionTester()
		.inputSize(13, 13)
		.iterations(100)
		.errorLimit(1.0e-3)
		.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_tuple_based);
}

/*
 * Test that the implementation handles implicit padding of input
 */

TEST(FT8x8_BLOCK, DISABLED_implicit_padding) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.kernelSize(5, 5)
		.iterations(5)
		.errorLimit(5.0e-2);
	for (size_t paddingTop = 0; paddingTop < tester.kernelHeight(); paddingTop++) {
		for (size_t paddingRight = 0; paddingRight < tester.kernelWidth(); paddingRight++) {
			for (size_t paddingLeft = 0; paddingLeft < tester.kernelWidth(); paddingLeft++) {
				for (size_t paddingBottom = 0; paddingBottom < tester.kernelHeight(); paddingBottom++) {
					tester.inputPadding(paddingTop, paddingRight, paddingBottom, paddingLeft)
						.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_block_based);
				}
			}
		}
	}
}

TEST(FT8x8_TUPLE, implicit_padding) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.kernelSize(5, 5)
		.iterations(5)
		.errorLimit(5.0e-2);
	for (size_t paddingTop = 0; paddingTop < tester.kernelHeight(); paddingTop++) {
		for (size_t paddingRight = 0; paddingRight < tester.kernelWidth(); paddingRight++) {
			for (size_t paddingLeft = 0; paddingLeft < tester.kernelWidth(); paddingLeft++) {
				for (size_t paddingBottom = 0; paddingBottom < tester.kernelHeight(); paddingBottom++) {
					tester.inputPadding(paddingTop, paddingRight, paddingBottom, paddingLeft)
						.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_tuple_based);
				}
			}
		}
	}
}

TEST(FT16x16_BLOCK, DISABLED_implicit_padding) {
	ConvolutionTester tester;
	tester.inputSize(16, 16)
		.kernelSize(5, 5)
		.iterations(5)
		.errorLimit(5.0e-2);
	for (size_t paddingTop = 0; paddingTop < tester.kernelHeight(); paddingTop++) {
		for (size_t paddingRight = 0; paddingRight < tester.kernelWidth(); paddingRight++) {
			for (size_t paddingLeft = 0; paddingLeft < tester.kernelWidth(); paddingLeft++) {
				for (size_t paddingBottom = 0; paddingBottom < tester.kernelHeight(); paddingBottom++) {
					tester.inputPadding(paddingTop, paddingRight, paddingBottom, paddingLeft)
						.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_block_based);
				}
			}
		}
	}
}

TEST(FT16x16_TUPLE, implicit_padding) {
	ConvolutionTester tester;
	tester.inputSize(16, 16)
		.kernelSize(5, 5)
		.iterations(5)
		.errorLimit(5.0e-2);
	for (size_t paddingTop = 0; paddingTop < tester.kernelHeight(); paddingTop++) {
		for (size_t paddingRight = 0; paddingRight < tester.kernelWidth(); paddingRight++) {
			for (size_t paddingLeft = 0; paddingLeft < tester.kernelWidth(); paddingLeft++) {
				for (size_t paddingBottom = 0; paddingBottom < tester.kernelHeight(); paddingBottom++) {
					tester.inputPadding(paddingTop, paddingRight, paddingBottom, paddingLeft)
						.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_tuple_based);
				}
			}
		}
	}
}

TEST(WT8x8_BLOCK, DISABLED_implicit_padding) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.kernelSize(3, 3)
		.iterations(15)
		.errorLimit(1.0e-1);
	for (size_t paddingTop = 0; paddingTop < tester.kernelHeight(); paddingTop++) {
		for (size_t paddingRight = 0; paddingRight < tester.kernelWidth(); paddingRight++) {
			for (size_t paddingLeft = 0; paddingLeft < tester.kernelWidth(); paddingLeft++) {
				for (size_t paddingBottom = 0; paddingBottom < tester.kernelHeight(); paddingBottom++) {
					tester.inputPadding(paddingTop, paddingRight, paddingBottom, paddingLeft)
						.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_block_based);
				}
			}
		}
	}
}

TEST(WT8x8_TUPLE, implicit_padding) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.kernelSize(3, 3)
		.iterations(15)
		.errorLimit(1.0e-1);
	for (size_t paddingTop = 0; paddingTop < tester.kernelHeight(); paddingTop++) {
		for (size_t paddingRight = 0; paddingRight < tester.kernelWidth(); paddingRight++) {
			for (size_t paddingLeft = 0; paddingLeft < tester.kernelWidth(); paddingLeft++) {
				for (size_t paddingBottom = 0; paddingBottom < tester.kernelHeight(); paddingBottom++) {
					tester.inputPadding(paddingTop, paddingRight, paddingBottom, paddingLeft)
						.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_tuple_based);
				}
			}
		}
	}
}

/*
 * Test that the implementation can handle small non-unit number of input channels
 */

TEST(FT8x8_BLOCK, DISABLED_few_input_channels) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-5);
	for (size_t inputChannels = 2; inputChannels <= 5; inputChannels++) {
		tester.inputChannels(inputChannels)
			.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_block_based);
	}
}

TEST(FT8x8_TUPLE, few_input_channels) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-5);
	for (size_t inputChannels = 2; inputChannels <= 5; inputChannels++) {
		tester.inputChannels(inputChannels)
			.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_tuple_based);
	}
}

TEST(FT16x16_BLOCK, DISABLED_few_input_channels) {
	ConvolutionTester tester;
	tester.inputSize(16, 16)
		.iterations(100)
		.errorLimit(1.0e-5);
	for (size_t inputChannels = 2; inputChannels <= 5; inputChannels++) {
		tester.inputChannels(inputChannels)
			.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_block_based);
	}
}

TEST(FT16x16_TUPLE, few_input_channels) {
	ConvolutionTester tester;
	tester.inputSize(16, 16)
		.iterations(100)
		.errorLimit(1.0e-5);
	for (size_t inputChannels = 2; inputChannels <= 5; inputChannels++) {
		tester.inputChannels(inputChannels)
			.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_tuple_based);
	}
}

TEST(WT8x8_BLOCK, DISABLED_few_input_channels) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-3);
	for (size_t inputChannels = 2; inputChannels <= 5; inputChannels++) {
		tester.inputChannels(inputChannels)
			.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_block_based);
	}
}

TEST(WT8x8_TUPLE, few_input_channels) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-3);
	for (size_t inputChannels = 2; inputChannels <= 5; inputChannels++) {
		tester.inputChannels(inputChannels)
			.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_tuple_based);
	}
}

/*
 * Test that the implementation can handle small non-unit number of output channels
 */

TEST(FT8x8_BLOCK, DISABLED_few_output_channels) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-5);
	for (size_t outputChannels = 2; outputChannels <= 5; outputChannels++) {
		tester.outputChannels(outputChannels)
			.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_block_based);
	}
}

TEST(FT8x8_TUPLE, few_output_channels) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-5);
	for (size_t outputChannels = 2; outputChannels <= 5; outputChannels++) {
		tester.outputChannels(outputChannels)
			.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_tuple_based);
	}
}

TEST(FT16x16_BLOCK, DISABLED_few_output_channels) {
	ConvolutionTester tester;
	tester.inputSize(16, 16)
		.iterations(100)
		.errorLimit(1.0e-5);
	for (size_t outputChannels = 2; outputChannels <= 5; outputChannels++) {
		tester.outputChannels(outputChannels)
			.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_block_based);
	}
}

TEST(FT16x16_TUPLE, few_output_channels) {
	ConvolutionTester tester;
	tester.inputSize(16, 16)
		.iterations(100)
		.errorLimit(1.0e-5);
	for (size_t outputChannels = 2; outputChannels <= 5; outputChannels++) {
		tester.outputChannels(outputChannels)
			.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_tuple_based);
	}
}

TEST(WT8x8_BLOCK, DISABLED_few_output_channels) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-3);
	for (size_t outputChannels = 2; outputChannels <= 5; outputChannels++) {
		tester.outputChannels(outputChannels)
			.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_block_based);
	}
}

TEST(WT8x8_TUPLE, few_output_channels) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.iterations(100)
		.errorLimit(1.0e-3);
	for (size_t outputChannels = 2; outputChannels <= 5; outputChannels++) {
		tester.outputChannels(outputChannels)
			.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_tuple_based);
	}
}

/*
 * Test that the implementation can handle non-square kernels
 */

TEST(FT8x8_BLOCK, DISABLED_non_square_kernel) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.kernelSize(2, 3)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_block_based);
}

TEST(FT8x8_TUPLE, non_square_kernel) {
	ConvolutionTester tester;
	tester.inputSize(8, 8)
		.kernelSize(2, 3)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_tuple_based);
}

TEST(FT16x16_BLOCK, DISABLED_non_square_kernel) {
	ConvolutionTester tester;
	tester.inputSize(16, 16)
		.kernelSize(2, 3)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_block_based);
}

TEST(FT16x16_TUPLE, non_square_kernel) {
	ConvolutionTester tester;
	tester.inputSize(16, 16)
		.kernelSize(2, 3)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_tuple_based);
}

/*
 * Test that the implementation can handle non-square images
 */

TEST(FT8x8_BLOCK, DISABLED_non_square_image) {
	ConvolutionTester tester;
	tester.inputSize(9, 10)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_block_based);
}

TEST(FT8x8_TUPLE, non_square_image) {
	ConvolutionTester tester;
	tester.inputSize(9, 10)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft8x8, nnp_convolution_transform_strategy_tuple_based);
}

TEST(FT16x16_BLOCK, DISABLED_non_square_image) {
	ConvolutionTester tester;
	tester.inputSize(17, 19)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_block_based);
}

TEST(FT16x16_TUPLE, non_square_image) {
	ConvolutionTester tester;
	tester.inputSize(17, 19)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_ft16x16, nnp_convolution_transform_strategy_tuple_based);
}

TEST(WT8x8_BLOCK, DISABLED_non_square_image) {
	ConvolutionTester tester;
	tester.inputSize(9, 10)
		.iterations(100)
		.errorLimit(1.0e-3)
		.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_block_based);
}

TEST(WT8x8_TUPLE, non_square_image) {
	ConvolutionTester tester;
	tester.inputSize(9, 10)
		.iterations(100)
		.errorLimit(1.0e-3)
		.testInference(nnp_convolution_algorithm_wt8x8, nnp_convolution_transform_strategy_tuple_based);
}


TEST(DIRECT_1x1, channel_tile) {
	ConvolutionTester()
		.inputSize(8, 8)
		.kernelSize(1, 1)
		.inputChannels(nnp_hwinfo.conv1x1.mr)
		.outputChannels(nnp_hwinfo.conv1x1.nr)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_direct);
}

TEST(DIRECT_1x1, channel_subtile) {
	for (size_t inputChannels = 1; inputChannels <= nnp_hwinfo.conv1x1.mr; inputChannels++) {
		for (size_t outputChannels = 1; outputChannels <= nnp_hwinfo.conv1x1.nr; outputChannels++) {
			if (inputChannels == nnp_hwinfo.conv1x1.mr && outputChannels == nnp_hwinfo.conv1x1.nr) {
				continue;
			}
			ConvolutionTester()
				.inputSize(8, 8)
				.kernelSize(1, 1)
				.inputChannels(inputChannels)
				.outputChannels(outputChannels)
				.iterations(100)
				.errorLimit(1.0e-5)
				.testInference(nnp_convolution_algorithm_direct);
		}
	}
}

TEST(DIRECT_1x1, input_multi_tile) {
	ConvolutionTester()
		.inputSize(8, 8)
		.kernelSize(1, 1)
		.inputChannels(nnp_hwinfo.conv1x1.mr * 3)
		.outputChannels(nnp_hwinfo.conv1x1.nr)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_direct);
}

TEST(DIRECT_1x1, output_multi_tile) {
	ConvolutionTester()
		.inputSize(8, 8)
		.kernelSize(1, 1)
		.inputChannels(nnp_hwinfo.conv1x1.mr)
		.outputChannels(nnp_hwinfo.conv1x1.nr * 5)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_direct);
}

TEST(DIRECT_1x1, input_output_multi_tile) {
	ConvolutionTester()
		.inputSize(8, 8)
		.kernelSize(1, 1)
		.inputChannels(nnp_hwinfo.conv1x1.mr * 5)
		.outputChannels(nnp_hwinfo.conv1x1.nr * 3)
		.iterations(100)
		.errorLimit(1.0e-5)
		.testInference(nnp_convolution_algorithm_direct);
}

TEST(DIRECT_1x1, odd_image_size) {
	for (size_t height = 1; height < 8; height++) {
		for (size_t width = 1; width < 8; width++) {
			if (height * width < nnp_hwinfo.simd_width) {
				continue;
			}

			for (size_t inputChannels = 1; inputChannels <= nnp_hwinfo.conv1x1.mr; inputChannels++) {
				for (size_t outputChannels = 1; outputChannels <= nnp_hwinfo.conv1x1.nr; outputChannels++) {
					ConvolutionTester()
						.inputSize(height, width)
						.kernelSize(1, 1)
						.inputChannels(nnp_hwinfo.conv1x1.mr + 1)
						.outputChannels(nnp_hwinfo.conv1x1.nr + 1)
						.iterations(100)
						.errorLimit(1.0e-5)
						.testInference(nnp_convolution_algorithm_direct);
				}
			}
		}
	}
}

int main(int argc, char* argv[]) {
	const enum nnp_status init_status = nnp_initialize();
	assert(init_status == nnp_status_success);
	setenv("TERM", "xterm-256color", 0);
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}

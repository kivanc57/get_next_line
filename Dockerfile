# Use gcc compiler for C
FROM gcc:14.2.0-bookworm

# Set the working directory
WORKDIR /usr/src/get_next_line

# Copy header files from the 'inc' directory
COPY inc ./inc

# Copy source files from the 'src' directory
COPY src ./src

# Copy text file
COPY text ./text

# Copy the MakeFile
COPY Makefile ./

# Execute make
RUN make

# Define the command to run the executable
CMD ["./get_next_line"]
